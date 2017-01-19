<?php
/**
 * @file
 * gestiune.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function gestiune_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_adauga-nir:node/add/nir.
  $menu_links['user-menu_adauga-nir:node/add/nir'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/nir',
    'router_path' => 'node/add/nir',
    'link_title' => 'Adauga NIR',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_adauga-nir:node/add/nir',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_nir-uri:nir-uri.
  $menu_links['user-menu_nir-uri:nir-uri'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'nir-uri',
    'router_path' => 'nir-uri',
    'link_title' => 'NIR-uri',
    'options' => array(
      'identifier' => 'user-menu_nir-uri:nir-uri',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adauga NIR');
  t('NIR-uri');

  return $menu_links;
}
