<?php
/**
 * @file
 * copiii.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function copiii_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|profile2|main|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date de contact',
    'weight' => '11',
    'children' => array(
      0 => 'field_email',
      1 => 'field_telefon',
      2 => 'field_term_judet',
      3 => 'field_fullname',
      4 => 'field_term_localitate',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|profile2|main|form'] = $field_group;

  return $export;
}
