<?php
/**
 * @file
 * financial_statement.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function financial_statement_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:budget-periods
  $menu_links['navigation:budget-periods'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'budget-periods',
    'router_path' => 'budget-periods',
    'link_title' => 'Periods',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Periods');


  return $menu_links;
}
