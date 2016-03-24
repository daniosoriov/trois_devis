<?php

/**
 * @file
 * Rules integration for line items credit note.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Rules integration access callback.
 */
function credit_note_rules_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return TRUE;
  }
}

/**
 * Implementation of hook_rules_action_info()
 */
function credit_note_rules_action_info() {
  return array(
    'credit_note_action_apply_credit_note' => array( // This is the name of the callback function
      'label' => t('Apply credit note to a line item'),
      'group' => t('Commerce Line Item'),
      'parameter' => array(
        'line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line Item'),
          'description' => t('The line item on which to apply the credit note.'),
          'wrapped' => true, // This is nice, it will be wrapped for us
          'save' => true,    // And saved too!
        ),
        'amount' => array(
          'type' => 'decimal',
          'label' => t('Amount'),
          'description' => t('The amount of the credit note. Note: Taxes will be added automatically later.'),
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
function credit_note_action_apply_credit_note($line_item_wrapper, $amount) {
  if (is_numeric($amount)) {
    //$amount = $amount * 1.21;
    $order = commerce_order_load($line_item_wrapper->value()->order_id);
    $total = 0;
    // Calculate the total of the order to see if the credit note can be applied.
    $lang = key($order->commerce_order_total);
    foreach ($order->commerce_order_total[$lang][0]['data']['components'] as $key => $data) {
      if ($data['name'] == 'base_price') {
        $total = $data['price']['amount'];
      }
    }
    // If the total of the order is greater than the value of the credit note.
    if ($total >= $amount) {
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
        'base_price', //'credit_note',
        $difference,
        TRUE
      );
      
      /*
      // Add the discount as a price component
      $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add(
        $line_item_wrapper->commerce_unit_price->value(),
        'credit_note',
        array(
          'amount' => $amount * -1,
          'currency_code' => 'EUR',
          'data' => array()
        ),
        0 // NOT included already in the price
      );*/
    }
  }
}