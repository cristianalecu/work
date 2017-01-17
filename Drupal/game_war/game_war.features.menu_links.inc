<?php
/**
 * @file
 * game_war.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function game_war_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_comandant:profile-main.
  $menu_links['user-menu_comandant:profile-main'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'profile-main',
    'router_path' => 'profile-main',
    'link_title' => 'Comandant',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_comandant:profile-main',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_stare-garnizoan:profile-garnizoan_.
  $menu_links['user-menu_stare-garnizoan:profile-garnizoan_'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'profile-garnizoan_',
    'router_path' => 'profile-garnizoan_',
    'link_title' => 'Stare garnizoană',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_stare-garnizoan:profile-garnizoan_',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comandant');
  t('Stare garnizoană');

  return $menu_links;
}
