<?php

/**
 * @file
 * Administration functions for the trois devis module.
 */

/**
 * Module settings form.
 */
function trois_devis_administration_form($form, &$form_state) {
  $form = array();
  $form['trois_devis_terms_nid'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Terms node ID'),
    '#description'   => t('Set the node ID used to get the terms information when showing the terms and conditions.'),
    '#default_value' => variable_get('trois_devis_terms_nid', ''),
    '#size'          => 10,
    '#maxlength'     => 10,
    '#required'      => TRUE,
  );
  $form['trois_devis_unsubscribe_confirm_nid'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Unsubscribe confirm node ID'),
    '#description'   => t('Set the node ID used to get the unsubscribe confirmation page.'),
    '#default_value' => variable_get('trois_devis_unsubscribe_confirm_nid', ''),
    '#size'          => 10,
    '#maxlength'     => 10,
    '#required'      => TRUE,
  );
  $form['trois_devis_hash_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Hash key'),
    '#description'   => t('Set the hash key to be used when creating strings with md5.'),
    '#default_value' => variable_get('trois_devis_hash_key', ''),
    '#size'          => 60,
    '#maxlength'     => 128,
    '#required'      => TRUE,
  );
  $var = 'Babylonia Communications sprl Bd. Saint-Michel 65/6 1040 Brussels VAT: BE 0843.545.553';
  $form['trois_devis_billing_address'] = array(
    '#type'          => 'textarea',
    '#title'         => t('3devis Billing address'),
    '#default_value' => variable_get('trois_devis_billing_address', $var),
    '#description'   => t('Set the billing address to display to users on their invoices.'),
  );
  
  $form['trois_devis_registration_promo_id'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Registration Promotion ID'),
    '#description'   => t('Specify the registration promotion ID, if 0, no promotion message will be shown or applied.'),
    '#size'          => 3,
    '#required'      => TRUE,
    '#default_value' => variable_get('trois_devis_registration_promo_id', 0),
  );
  
  $form['meta'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Metatag'),
    '#description'   => t('Set the head meta information.'),
    '#collapsible'   => FALSE,
    '#collapsed'     => FALSE,
  );
  $form['meta']['budget_request'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Budget request'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
  );
  $form['meta']['budget_request']['trois_devis_comptable_title'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Accountant request title'),
    '#description'   => t('Set the title for the page on: eform/submit/comptable.'),
    '#default_value' => variable_get('trois_devis_comptable_title', ''),
    '#size'          => 100,
    '#maxlength'     => 250,
    '#required'      => TRUE,
  );
  $form['meta']['budget_request']['trois_devis_comptable_description'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Accountant request description'),
    '#description'   => t('Set the description for the page on: eform/submit/comptable.'),
    '#default_value' => variable_get('trois_devis_comptable_description', ''),
    '#required'      => TRUE,
  );
  $form['meta']['budget_request']['trois_devis_budget_photographer_title'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Photographer request title'),
    '#description'   => t('Set the title for the page on: eform/submit/budget-photographer.'),
    '#default_value' => variable_get('trois_devis_budget_photographer_title', ''),
    '#size'          => 100,
    '#maxlength'     => 250,
    '#required'      => TRUE,
  );
  $form['meta']['budget_request']['trois_devis_budget_photographer_description'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Photographer request description'),
    '#description'   => t('Set the description for the page on: eform/submit/budget-photographer.'),
    '#default_value' => variable_get('trois_devis_budget_photographer_description', ''),
    '#required'      => TRUE,
  );
  
  $form['meta']['become_provider'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Become provider'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
  );
  $form['meta']['become_provider']['trois_devis_devenir_title'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Accountant title'),
    '#description'   => t('Set the title for the page on: eform/submit/devenir.'),
    '#default_value' => variable_get('trois_devis_devenir_title', ''),
    '#size'          => 100,
    '#maxlength'     => 250,
    '#required'      => TRUE,
  );
  $form['meta']['become_provider']['trois_devis_devenir_description'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Accountant description'),
    '#description'   => t('Set the description for the page on: eform/submit/devenir.'),
    '#default_value' => variable_get('trois_devis_devenir_description', ''),
    '#required'      => TRUE,
  );
  $form['meta']['become_provider']['trois_devis_devenir_photographe_title'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Photographer title'),
    '#description'   => t('Set the title for the page on: eform/submit/devenir-fournisseur-photographe.'),
    '#default_value' => variable_get('trois_devis_devenir_photographe_title', ''),
    '#size'          => 100,
    '#maxlength'     => 250,
    '#required'      => TRUE,
  );
  $form['meta']['become_provider']['trois_devis_devenir_photographe_description'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Photographer description'),
    '#description'   => t('Set the description for the page on: eform/submit/devenir-fournisseur-photographe.'),
    '#default_value' => variable_get('trois_devis_devenir_photographe_description', ''),
    '#required'      => TRUE,
  );
  
  $form['scheduler'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Scheduler'),
    '#description'   => t('Set the scheduler.'),
    '#collapsible'   => FALSE,
    '#collapsed'     => FALSE,
  );
  $form['scheduler']['trois_devis_reset_count'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Activate monthly reset count for providers.'),
    '#default_value' => variable_get('trois_devis_reset_count', 0),
    '#description'   => t('Check to activate the monthly scheduler for this task. It will be executed the first of each month at 00:01'),
  );
  $form['scheduler']['trois_devis_check_budget'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Check budgets for new providers.'),
    '#default_value' => variable_get('trois_devis_check_budget', 0),
    '#description'   => t('Check to activate the hourly scheduler for this task. It will be executed every hour.'),
  );
  
  $form['steps'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Steps'),
    '#description'   => t('Set the steps variables for the user while registering.'),
    '#collapsible'   => FALSE,
    '#collapsed'     => FALSE,
  );
  $form['steps']['trois_devis_first_step_message'] = array(
    '#type'          => 'textarea',
    '#title'         => t('1st step message'),
    '#default_value' => variable_get('trois_devis_first_step_message', ''),
    '#description'   => t('Set the first step message to show to the users.'),
  );
  $form['steps']['trois_devis_second_step_message'] = array(
    '#type'          => 'textarea',
    '#title'         => t('2nd step message'),
    '#default_value' => variable_get('trois_devis_second_step_message', ''),
    '#description'   => t('Set the second step message to show to the users.'),
  );
  $form['steps']['trois_devis_third_step_message'] = array(
    '#type'          => 'textarea',
    '#title'         => t('3rd step message'),
    '#default_value' => variable_get('trois_devis_third_step_message', ''),
    '#description'   => t('Set the third step message to show to the users.'),
  );
  $form['#submit'][] = 'trois_devis_administration_form_submit';
  $form = system_settings_form($form);
  return $form;
}

function trois_devis_administration_form_submit($form, &$form_state) {
  // Provider monthly count reset.
  $reset_count = variable_get('trois_devis_reset_count', 0);
  if ($reset_count) {
    // Create a default scheduled job.
    // Run every 1st of month at 00:01 to reset the count.
    $job = array(
      'type'     => 'troid_devis_reset',
      'id'       => 1,
      'crontab'  => '1 0 1 * *',
      'periodic' => TRUE,
    );
    JobScheduler::get('trois_devis_reset_task')->set($job);
  }
  else {
    $job = array('type' => 'troid_devis_reset', 'id' => 1);
    JobScheduler::get('trois_devis_reset_task')->remove($job);
  }
  
  // Contact new providers.
  $check_budget = variable_get('trois_devis_check_budget', 0);
  if ($check_budget) {
    // Create a default scheduled job.
    // Run every hour.
    $job = array(
      'type'     => 'trois_devis_check_budget',
      'id'       => 1,
      'period'   => 3600,
      'crontab'  => '0 * * * *',
      'periodic' => TRUE,
    );
    JobScheduler::get('trois_devis_check_budget_task')->set($job);
  }
  else {
    $job = array('type' => 'trois_devis_check_budget', 'id' => 1);
    JobScheduler::get('trois_devis_check_budget_task')->remove($job);
  }
  
  drupal_set_message(t('Your configuration has been saved.'));
}

function trois_devis_administration_template_form($form, &$form_state, $entityform_id) {
  $form = array();
  $form['entityform_id'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Budget ID'),
    '#description'   => t('Specify the budget ID to generate the e-mail template.'),
    '#size'          => 3,
    '#required'      => TRUE,
    '#default_value' => ($entityform_id) ? $entityform_id : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate template'),
    '#suffix' => ($entityform_id) ? l('Back to Budget request '. $entityform_id, 'entityform/'. $entityform_id) : '',
  );
  /*if ($entityform_id) {
    $entityform = entityform_load($entityform_id);
    $form_state['template'] = trois_devis_create_entityform_template($entityform, null, TRUE);
  }*/
  if ($form_state['template']) {
    $form['field_name'] = array(
      '#type' => 'text_format',
      '#format' => 'full_html_advanced_manager',
      '#title' => t('E-mail Template'),
      '#default_value' => $form_state['template'],
      '#description' => t('This is the E-mail template in full HTML.'),
    );
  }
  return $form;
}

function trois_devis_administration_template_form_validate($form, &$form_state) {
  $entityform_id = $form_state['values']['entityform_id'];
  element_validate_integer_positive($form['entityform_id'], $form_state);
  if (form_get_errors()) return;
  $entityform = entityform_load($entityform_id);
  if (!$entityform) {
    form_set_error('entityform_id', t('Not a valid entityform ID.'));
  }
  else {
    if ($entityform->type != 'comptable') {
      form_set_error('entityform_id', t('This budget ID is not of the correct type.'));
    }
    else {
      $form_state['entityform'] = $entityform;
    }
  }
}

function trois_devis_administration_template_form_submit($form, &$form_state) {
  $form_state['template'] = trois_devis_create_entityform_template($form_state['entityform'], null, TRUE);
  $form_state['rebuild'] = TRUE;
}

