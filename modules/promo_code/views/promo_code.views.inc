<?php
/**
 * @file
 * Views integration.
 */
 
/**
* Implements hook_views_data().
*/
function promo_code_views_data() {
  // Promo Code.
  $data['devis_promo_code']['table']['group'] = t('Promo Code');
  // Advertise this table as a possible base table
  $data['devis_promo_code']['table']['base'] = array(
    'field' => 'cid',
    'title' => t('Promo Code'),
    'help' => t('This table contains information about promo codes.'),
    'weight' => -15,
  );
  
  $data['devis_promo_code']['code'] = array(
    'title' => t('Promo Code'),
    'help' => t('Promo code name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['devis_promo_code']['discount'] = array(
    'title' => t('Discount'),
    'help' => t('Amount of the promo code.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['devis_promo_code']['date_begin'] = array(
    'title' => t('Begin Date'), // The item it appears as on the UI,
    'help' => t('The date the promo code starts.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  $data['devis_promo_code']['date_end'] = array(
    'title' => t('End Date'), // The item it appears as on the UI,
    'help' => t('The date the promo code ends.'), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  
  
  // Promo Code Usage.
  $data['devis_promo_code_usage']['table']['group'] = t('Promo Code Usage');
  // Advertise this table as a possible base table
  $data['devis_promo_code_usage']['table']['base'] = array(
    'field' => 'cid',
    'title' => t('Promo Code Usage'),
    'help' => t('This table contains information about the usage of promo codes by the providers.'),
    'weight' => -10,
  );
  
  $data['devis_promo_code_usage']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'devis_promo_code' => array(
      'left_field' => 'cid',
      'field' => 'cid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'commerce_order' => array(
      'left_field' => 'order_id',
      'field' => 'order_id',
    ),
  );
  
  $data['devis_promo_code_usage']['cid'] = array(
    'title' => t('Promo Code'),
    'help' => t('Code that references the Promo Code.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'devis_promo_code', // The name of the table to join with.
      'base field' => 'cid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Promo Code'),
      'title' => t('Promo Code Association'),
      'help' => t('Brings the information about the promo code'),
    ),
  );
  
  $data['devis_promo_code_usage']['uid'] = array(
    'title' => t('Provider'),
    'help' => t('Provider that references an user.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'users', // The name of the table to join with.
      'base field' => 'uid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
      'title' => t('User Association'),
      'help' => t('Brings the information about the provider'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['devis_promo_code_usage']['order_id'] = array(
    'title' => t('Order'),
    'help' => t('Order that references the Commerce Order.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'commerce_order', // The name of the table to join with.
      'base field' => 'order_id', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Order'),
      'title' => t('Order Association'),
      'help' => t('Brings the information about the order where the promo code was used'),
    ),
  );
  
  $data['devis_promo_code_usage']['code_usage'] = array(
    'title' => t('Promo Code Usage'),
    'help' => t('Amount of the promo code used.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}