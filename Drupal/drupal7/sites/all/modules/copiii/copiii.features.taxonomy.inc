<?php
/**
 * @file
 * copiii.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function copiii_taxonomy_default_vocabularies() {
  return array(
    'categorii_coloreaz_online' => array(
      'name' => 'Categorii colorează online',
      'machine_name' => 'categorii_coloreaz_online',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'categorii_jocuri_educative' => array(
      'name' => 'Categorii jocuri educative',
      'machine_name' => 'categorii_jocuri_educative',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'jude_e' => array(
      'name' => 'Judeţe',
      'machine_name' => 'jude_e',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'localit_i' => array(
      'name' => 'Localităţi',
      'machine_name' => 'localit_i',
      'description' => '',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'planse' => array(
      'name' => 'Categorii Planse',
      'machine_name' => 'planse',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
