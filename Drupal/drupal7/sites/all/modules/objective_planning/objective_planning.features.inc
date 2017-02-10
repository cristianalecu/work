<?php
/**
 * @file
 * objective_planning.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function objective_planning_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function objective_planning_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function objective_planning_node_info() {
  $items = array(
    'objective' => array(
      'name' => t('Objective'),
      'base' => 'node_content',
      'description' => t('Objectives to plan'),
      'has_title' => '1',
      'title_label' => t('Objective'),
      'help' => '',
    ),
  );
  return $items;
}
