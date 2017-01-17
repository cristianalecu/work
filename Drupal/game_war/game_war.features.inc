<?php
/**
 * @file
 * game_war.features.inc
 */

/**
 * Implements hook_node_info().
 */
function game_war_node_info() {
  $items = array(
    'set_ri' => array(
      'name' => t('Setări'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Setare'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function game_war_default_profile2_type() {
  $items = array();
  $items['garnizoan_'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "garnizoan_",
    "label" : "Garnizoan\\u0103",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Date comandant",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
