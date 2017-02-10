<?php
/**
 * @file
 * _thiswebsite.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function _thiswebsite_taxonomy_default_vocabularies() {
  return array(
    '_tiri' => array(
      'name' => 'Ştiri',
      'machine_name' => '_tiri',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
