<?php
/**
 * @file
 * objective_planning.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function objective_planning_field_default_fields() {
  $fields = array();

  // Exported field: 'node-objective-field_obj_emotions'
  $fields['node-objective-field_obj_emotions'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_obj_emotions',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'objective',
    ),
    'field_instance' => array(
      'bundle' => 'objective',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<b>WHY ? </b> Enter the strongest emotion(s) that determine you to have this objective, and can sustain you for a long period:
<ul><li>Intimate feelings of ambition, passion, revenge, desire to date nice men/women
<li>To be rewarded, to prove something, to be recognized
<li>Satisfaction, prove to yourself that you are a winner
<li>You want it for the family, people you love, help friends
<li>To be grateful and share it with others</ul>',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        2 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        3 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        4 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_obj_emotions',
      'label' => 'Emotions',
      'required' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '14',
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '3',
      ),
      'widget_type' => 'text_textarea',
    ),
  );

  // Exported field: 'node-objective-field_obj_milestone'
  $fields['node-objective-field_obj_milestone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_obj_milestone',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'default_format' => 'medium',
        'granularity' => array(
          'day' => 'day',
          'month' => 'month',
          'year' => 'year',
        ),
        'repeat' => 0,
        'repeat_collapsed' => '',
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'date',
      'type_name' => 'objective',
    ),
    'field_instance' => array(
      'bundle' => 'objective',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'medium',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_medium',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'short',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_short',
          'weight' => '12',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '12',
        ),
        2 => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '12',
        ),
        3 => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '12',
        ),
        4 => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => '12',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_obj_milestone',
      'label' => 'Milestone',
      'required' => FALSE,
      'settings' => array(
        'default_format' => 'medium',
        'default_value' => 'now',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '12',
      'widget' => array(
        'active' => '1',
        'module' => 'date',
        'settings' => array(
          'increment' => '1',
          'input_format' => 'd.m.Y',
          'input_format_custom' => '',
          'label_position' => 'within',
          'repeat_collapsed' => '',
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => '1',
      ),
      'widget_type' => 'date_popup',
    ),
  );

  // Exported field: 'node-objective-field_obj_person'
  $fields['node-objective-field_obj_person'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_obj_person',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'objective',
    ),
    'field_instance' => array(
      'bundle' => 'objective',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<b>How should I be ? </b> Write what kind of person you want to be to complete your objective.<br>
Start by saying that you trust yourself and believe you can do it.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
        2 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
        3 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
        4 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_obj_person',
      'label' => 'Person',
      'required' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '15',
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '4',
      ),
      'widget_type' => 'text_textarea',
    ),
  );

  // Exported field: 'node-objective-field_obj_plansteps'
  $fields['node-objective-field_obj_plansteps'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_obj_plansteps',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'objective',
    ),
    'field_instance' => array(
      'bundle' => 'objective',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<b>What TO DO ? </b> Write the actions you should make, in steps, as detailed as possible, to achieve the goal.

Write small steps. You don\'t need to see the whole road, only the next 50 foots, and the indicators.

You must follow it and then  develop / increase / improve  it every time you find new ways to your goal and have more experiences.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '17',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '17',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '17',
        ),
        2 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '17',
        ),
        3 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '17',
        ),
        4 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '17',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_obj_plansteps',
      'label' => 'The plan',
      'required' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '17',
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '6',
      ),
      'widget_type' => 'text_textarea',
    ),
  );

  // Exported field: 'node-objective-field_obj_study'
  $fields['node-objective-field_obj_study'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_obj_study',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'objective',
    ),
    'field_instance' => array(
      'bundle' => 'objective',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '<b>What should I know ? </b> Write what do you think you should read, learn, understand, know in order to achieve your objective.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '16',
        ),
        'token' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '16',
        ),
        2 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '16',
        ),
        3 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '16',
        ),
        4 => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '16',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_obj_study',
      'label' => 'Study',
      'required' => 1,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '16',
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '5',
      ),
      'widget_type' => 'text_textarea',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<b>How should I be ? </b> Write what kind of person you want to be to complete your objective.<br>
Start by saying that you trust yourself and believe you can do it.');
  t('<b>WHY ? </b> Enter the strongest emotion(s) that determine you to have this objective, and can sustain you for a long period:
<ul><li>Intimate feelings of ambition, passion, revenge, desire to date nice men/women
<li>To be rewarded, to prove something, to be recognized
<li>Satisfaction, prove to yourself that you are a winner
<li>You want it for the family, people you love, help friends
<li>To be grateful and share it with others</ul>');
  t('<b>What TO DO ? </b> Write the actions you should make, in steps, as detailed as possible, to achieve the goal.

Write small steps. You don\'t need to see the whole road, only the next 50 foots, and the indicators.

You must follow it and then  develop / increase / improve  it every time you find new ways to your goal and have more experiences.');
  t('<b>What should I know ? </b> Write what do you think you should read, learn, understand, know in order to achieve your objective.');
  t('Emotions');
  t('Milestone');
  t('Person');
  t('Study');
  t('The plan');

  return $fields;
}
