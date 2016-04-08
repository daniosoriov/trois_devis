<?php
/**
 * @file
 * A file to include Views API functions.
 */

/**
 * Implements hook_views_query_alter().
 * @param object $view 
 *  The view object about to be processed.
 * @param object $query
 *  An object describing the query.
 */
function views_alter_views_query_alter(&$view, &$query) {
  switch ($view->name) {
    case 'provider':
      switch ($view->current_display) {
        case 'provider_report_list':
          if ($view->exposed_raw_input['type'] && $view->exposed_raw_input['type'] == 'in_limbo') {
            if (isset($query->where[1]['conditions'])) {
              foreach ($query->where[1]['conditions'] as $k => $cond) {
                if ($cond['field'] == 'profile_users.type') {
                  $query->where[1]['conditions'][$k]['value'] = NULL;
                  $query->where[1]['conditions'][$k]['operator'] = 'IS';
                }
              }
            }
          }
          break;
      }
      /*if (strcmp($view->current_display, 'accountants_to_contact') == 0) {
        $query->add_table('profile_users__field_data_field_contacted_this_month','profile_users__field_data_field_number_budgets');
        $query->add_where_expression(0, 'profile_users__field_data_field_contacted_this_month.field_contacted_this_month_value < profile_users__field_data_field_number_budgets.field_number_budgets_value');
      }*/
      // Make credit cards be valid by the time of contacting a user.
      /*if ($view->current_display == 'accountants_to_contact_new') {
        $query->add_table('commerce_cardonfile_users');
        $query->add_where_expression(0, "DATEDIFF(CONCAT_WS('-', commerce_cardonfile_users.card_exp_year, LPAD(commerce_cardonfile_users.card_exp_month, 2, '0'), '01'), NOW()) > 0");
      }*/
      break;

    case 'budget_list':
      if (strcmp($view->current_display, 'budgets_previous_month') == 0) {
        $query->add_table('entityform');
        $query->add_where_expression(0, '(YEAR(FROM_UNIXTIME(entityform.created)) = YEAR(DATE_SUB(CURDATE(), INTERVAL 1 MONTH)) AND MONTH(FROM_UNIXTIME(entityform.created)) = MONTH(DATE_SUB(CURDATE(), INTERVAL 1 MONTH)))');
      }
      break;
    
    case 'user_has_promo_code':
      $query->add_table('field_data_field_promotional_code');
      $code = variable_get('trois_devis_promotion_code', 'SOMETHING');
      $query->add_where_expression(0, "field_data_field_promotional_code.field_promotional_code_value LIKE '". $code ."'");
      break;
  }
}

function views_alter_field_views_data_alter(&$result, $field, $module) {
  //dpm($field, 'field');
}

function views_alter_field_views_data_views_data_alter(&$data, $field) {
  //dpm('hola');
}

function views_alter_views_data_alter(&$data) {
  //dpm($data, 'data');
}