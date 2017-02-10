<?php
/**
 * @file
 * objective_planning.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function objective_planning_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:node/add/objective
  $menu_links['navigation:node/add/objective'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/objective',
    'router_path' => 'node/add/objective',
    'link_title' => 'Objective',
    'options' => array(
      'attributes' => array(
        'title' => 'Objectives to plan',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:userobjectives
  $menu_links['navigation:userobjectives'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'userobjectives',
    'router_path' => 'userobjectives',
    'link_title' => 'My Objectives',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My Objectives');
  t('Objective');


  return $menu_links;
}
