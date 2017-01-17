<?php
/**
 * @file
 * gestiune.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function gestiune_taxonomy_default_vocabularies() {
  return array(
    'supplier_vendor' => array(
      'name' => 'Supplier Vendor',
      'machine_name' => 'supplier_vendor',
      'description' => 'Furnizor',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
