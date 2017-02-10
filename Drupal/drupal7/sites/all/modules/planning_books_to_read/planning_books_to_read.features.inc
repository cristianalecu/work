<?php
/**
 * @file
 * planning_books_to_read.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function planning_books_to_read_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function planning_books_to_read_node_info() {
  $items = array(
    'books_to_read' => array(
      'name' => t('Books to read'),
      'base' => 'node_content',
      'description' => t('List of books I plan to read'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
