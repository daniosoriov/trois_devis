<?php

/**
 * @file
 * Rules integration for line items promo code.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Rules integration access callback.
 */
function promo_code_rules_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return TRUE;
  }
}

/**
 * Implementation of hook_rules_action_info()
 */
function promo_code_rules_action_info() {
  return array(
    'promo_code_action_apply_promo_code' => array( // This is the name of the callback function
      'label' => t('Apply promotion to a line item'),
      'group' => t('Commerce Line Item'),
      'parameter' => array(
        'line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line Item'),
          'description' => t('The line item on which to apply the promotion.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
          'save' => true,    // And saved too!
        ),
      ),
    ),
  );
}

/**
 * Rules action that applies a volume discount to an order
 * @param commerce_line_item $line_item
 * @return type
 */
function promo_code_action_apply_promo_code($line_item_wrapper) {
  $order = commerce_order_load($line_item_wrapper->value()->order_id);
  $account = user_load($order->uid);
  $user_usage = promo_code_user_has_usage_available($account);
  $order_total = promo_code_get_order_total($order);
  if ($user_usage && $order_total > 0) {
    $amount = min($order_total, ($user_usage['discount'] - $user_usage['used']));
    // If indeed the amount to apply is greater than 0.
    if ($amount > 0) {
      $unit_price = commerce_price_wrapper_value($line_item_wrapper, 'commerce_unit_price', TRUE);
      // Calculate the updated amount and create a price array representing the
      // difference between it and the current amount.
      $current_amount = $unit_price['amount'];
      $updated_amount = $amount * -1;

      $difference = array(
        'amount' => $updated_amount - $current_amount,
        'currency_code' => $unit_price['currency_code'],
        'data' => array(),
      );

      // Set the amount of the unit price and add the difference as a component.
      $line_item_wrapper->commerce_unit_price->amount = $updated_amount;

      $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add(
        $line_item_wrapper->commerce_unit_price->value(),
        'promo_premier', //'base_price',
        $difference,
        TRUE
      );
    }
  }
}

/**
 * Gets the total amount for an order. Useful to see if the promo code
 * can be applied with rules.
 */
function promo_code_get_order_total($order) {
  $total = 0;
  // Calculate the total of the order to see if the promo code can be applied.
  $lang = key($order->commerce_order_total);
  foreach ($order->commerce_order_total[$lang][0]['data']['components'] as $key => $data) {
    if ($data['name'] == 'base_price') {
      $total = $data['price']['amount'];
    }
  }
  return $total;
}