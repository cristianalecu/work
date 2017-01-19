<?php
// $Id$
/**
 * @file
 *
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function game_war_form_system_theme_settings_alter(&$form, &$form_state) {
  $values = array();

  $val = theme_get_setting('ellington_ie6nomore');

  $values['game_war_ie6nomore'] = is_null($val) ? '1' : $val;

  // Create the form
  $form['game_war_ie6nomore'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable IE6 no more script'),
    '#description' => t('Show IE6 no more toolbar if the user use Internet Explorer 6. See details: !url',
        array('!url' => l('http://www.ie6nomore.com/', 'http://www.ie6nomore.com', array('attributes' => array('target' => '_blank'))))),
    '#default_value' => $values['game_war_ie6nomore'],
  );
}