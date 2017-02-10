<?php
/**
 * @file
 * planning_books_to_read.features.menu_links.inc
 */

/**
 * Implementation of hook_menu_default_menu_links().
 */
function planning_books_to_read_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:allbooks
  $menu_links['navigation:allbooks'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'allbooks',
    'router_path' => 'allbooks',
    'link_title' => 'All Books',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:allbooks/mybooks
  $menu_links['navigation:allbooks/mybooks'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'allbooks/mybooks',
    'router_path' => 'allbooks/mybooks',
    'link_title' => 'My Books',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'allbooks',
  );
  // Exported menu link: navigation:node/add/books-to-read
  $menu_links['navigation:node/add/books-to-read'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/books-to-read',
    'router_path' => 'node/add/books-to-read',
    'link_title' => 'Books to read',
    'options' => array(
      'attributes' => array(
        'title' => 'List of books I plan to read',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('All Books');
  t('Books to read');
  t('My Books');


  return $menu_links;
}
