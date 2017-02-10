<?php
/**
 * @file
 * _thiswebsite.features.inc
 */

/**
 * Implements hook_views_api().
 */
function _thiswebsite_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function _thiswebsite_node_info() {
  $items = array(
    'articol' => array(
      'name' => t('Articol'),
      'base' => 'node_content',
      'description' => t('Articole Ştiri Noutăţi'),
      'has_title' => '1',
      'title_label' => t('Titlu'),
      'help' => '',
    ),
  );
  return $items;
}
