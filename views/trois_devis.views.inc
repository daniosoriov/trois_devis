<?php
/**
 * @file
 * Views integration.
 */
 
/**
* Implements hook_views_data().
*/
function trois_devis_views_data() {
  $data['devis_provider_assoc']['table']['group'] = t('Budget-Provider Association');
  // Advertise this table as a possible base table
  $data['devis_provider_assoc']['table']['base'] = array(
    'field' => 'entityform_id',
    'title' => t('Budget-Provider Association'),
    'help' => t('This table contains information about the budgets and the providers contacted.'),
    'weight' => -10,
  );
  
  $data['devis_provider_assoc']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'entityform' => array(
      'left_field' => 'entityform_id',
      'field' => 'entityform_id',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  
  $data['devis_provider_assoc']['entityform_id'] = array(
    'title' => t('Budget'),
    'help' => t('Budget that references an entityform.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'entityform', // The name of the table to join with.
      'base field' => 'entityform_id', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Entityform'),
      'title' => t('Entityform Association'),
      'help' => t('Brings the information about the entityform'),
    ),
  );
  
  $data['devis_provider_assoc']['uid'] = array(
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
      'help' => t('Brings the information about the contacted provider'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['devis_provider_assoc']['contacted'] = array(
    'title' => t('Contacted Date'), // The item it appears as on the UI,
    'help' => t('The date the provider was contacted the first time.'), // The help that appears on the UI,
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
  
  $data['devis_provider_assoc']['until_date'] = array(
    'title' => t('Until Date'), // The item it appears as on the UI,
    'help' => t('The date until which the provider can view and accept the request.'), // The help that appears on the UI,
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
  
  $data['devis_provider_assoc']['opened_date'] = array(
    'title' => t('Opened Date'), // The item it appears as on the UI,
    'help' => t('The date the provider opened the request.'), // The help that appears on the UI,
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
  
  $data['devis_provider_assoc']['date'] = array(
    'title' => t('Viewed Date'), // The item it appears as on the UI,
    'help' => t('The date the provider saw the budget fully.'), // The help that appears on the UI,
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
  
  $data['devis_provider_assoc']['url_accept'] = array(
    'title' => t('Accept Hash'),
    'help' => t('Hash URL to accept/preview the budget.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE, // This is use by the table display plugin.
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['devis_provider_assoc']['url_info'] = array(
    'title' => t('Budget Hash'),
    'help' => t('Hash URL to view the budget.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE, // This is use by the table display plugin.
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  return $data;
}