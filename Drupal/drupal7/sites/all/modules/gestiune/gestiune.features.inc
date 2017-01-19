<?php
/**
 * @file
 * gestiune.features.inc
 */

/**
 * Implements hook_views_api().
 */
function gestiune_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function gestiune_node_info() {
  $items = array(
    'nir' => array(
      'name' => t('NIR'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Denumire'),
      'help' => '',
    ),
    'produs' => array(
      'name' => t('Produs'),
      'base' => 'node_content',
      'description' => t('Produs gestionat'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'upload_items' => array(
      'name' => t('Upload items'),
      'base' => 'node_content',
      'description' => t('Upload database items xml  in xml format'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
