<?php

/**
 * @file
 * Administration functions for the credit note module.
 */

/**
 * Module settings form.
 */
function credit_note_administration_form($form_state) {
  
  rules_invoke_event('credit_note_action_apply_credit_note');
  
  $form = array();
  $form['credit_note_uid'] = array(
    '#type'          => 'textfield',
    '#title'         => t('User ID'),
    '#description'   => t('Set the user ID which will receive a credit note.'),
    '#size'          => 10,
    '#maxlength'     => 10,
  );
  $form['credit_note_rules_export'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Rules example'),
    '#default_value' => variable_get('credit_note_rules_export', ''),
    '#description'   => t('This is the rule you should create after adding the credit note to the user. Replace rule ID, account ID, date and amount.'),
  );
  $form['#submit'][] = 'credit_note_administration_form_submit';
  $form = system_settings_form($form);
  return $form;
}

function credit_note_administration_form_submit($form, &$form_state) {
  if ($form_state['values']['credit_note_uid']) {
    credit_note_add_credit_note_line_item($form_state['values']['credit_note_uid']);
  }
}