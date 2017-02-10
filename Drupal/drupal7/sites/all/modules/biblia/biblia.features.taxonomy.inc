<?php
/**
 * @file
 * biblia.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function biblia_taxonomy_default_vocabularies() {
  return array(
    'traduceri' => array(
      'name' => 'Traduceri',
      'machine_name' => 'traduceri',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
