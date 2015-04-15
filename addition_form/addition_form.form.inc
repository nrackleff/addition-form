<?php
/**
 * @file
 * Contains functions related to creating, displaying and validating the addition form.
 */

/**
 * The page callback.
 */
function addition_form_page() {
  return drupal_get_form('addition_form');
}


/**
 * The addition form.
 */
function addition_form($form, &$form_state) {
  $form['first-num'] = array(
    '#type' => 'textfield',
    '#title' => t('First Number'),
    '#required' => TRUE,
  );

  $form['second-num'] = array(
    '#type' => 'textfield',
    '#title' => t('Second Number'),
    '#required' => TRUE,
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Validation handler.
 */
function addition_form_validate(&$form, &$form_state) {
  if (!is_numeric($form_state['values']['first-num'])) {
    form_set_error('first-num', t("The first number must be a numeric."));
  }
  if (!is_numeric($form_state['values']['second-num'])) {
    form_set_error('first-num', t("The second number must be a numeric."));
  }
}

/**
 * Submit handler.
 */
function addition_form_submit(&$form, &$form_state) {
  $num1 = $form_state['values']['first-num'];
  $num2 = $form_state['values']['second-num'];
  $sum = $num1 + $num2;
  drupal_set_message(t('@first plus @second equals @sum.', array('@first' => $num1, '@second' => $num2, '@sum' => $sum)));
}
