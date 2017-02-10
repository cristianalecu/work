<?php
/**
 * @file
 * financial_statement.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function financial_statement_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function financial_statement_node_info() {
  $items = array(
    'asset' => array(
      'name' => t('Asset'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'budget_payment' => array(
      'name' => t('Budget Payment'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Reason'),
      'help' => '',
    ),
    'budget_record' => array(
      'name' => t('Budget Income'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Reason'),
      'help' => '',
    ),
  );
  return $items;
}
