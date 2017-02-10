<?php
/**
 * @file
 * planning_books_to_read.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function planning_books_to_read_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'all_books';
  $view->description = 'All Books';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Books';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Books';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_book_author' => 'field_book_author',
    'field_book_category' => 'field_book_category',
    'field_book_read' => 'field_book_read',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = 'field_book_read';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_book_author' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_book_category' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_book_read' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Authors */
  $handler->display->display_options['fields']['field_book_author']['id'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['fields']['field_book_author']['field'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_author']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_book_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_author']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_author']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_book_author']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_book_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_book_author']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_book_author']['field_api_classes'] = 0;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_book_category']['id'] = 'field_book_category';
  $handler->display->display_options['fields']['field_book_category']['table'] = 'field_data_field_book_category';
  $handler->display->display_options['fields']['field_book_category']['field'] = 'field_book_category';
  $handler->display->display_options['fields']['field_book_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_category']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_book_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_category']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_book_category']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_book_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_book_category']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_book_category']['field_api_classes'] = 0;
  /* Field: Content: Plan reading until */
  $handler->display->display_options['fields']['field_book_read']['id'] = 'field_book_read';
  $handler->display->display_options['fields']['field_book_read']['table'] = 'field_data_field_book_read';
  $handler->display->display_options['fields']['field_book_read']['field'] = 'field_book_read';
  $handler->display->display_options['fields']['field_book_read']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_read']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_read']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_read']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_book_read']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_read']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_read']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_read']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_book_read']['settings'] = array(
    'interval' => '2',
  );
  $handler->display->display_options['fields']['field_book_read']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'books_to_read' => 'books_to_read',
  );
  /* Filter criterion: Content: Category (field_book_category) */
  $handler->display->display_options['filters']['field_book_category_tid']['id'] = 'field_book_category_tid';
  $handler->display->display_options['filters']['field_book_category_tid']['table'] = 'field_data_field_book_category';
  $handler->display->display_options['filters']['field_book_category_tid']['field'] = 'field_book_category_tid';
  $handler->display->display_options['filters']['field_book_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_category_tid']['expose']['operator_id'] = 'field_book_category_tid_op';
  $handler->display->display_options['filters']['field_book_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_book_category_tid']['expose']['operator'] = 'field_book_category_tid_op';
  $handler->display->display_options['filters']['field_book_category_tid']['expose']['identifier'] = 'field_book_category_tid';
  $handler->display->display_options['filters']['field_book_category_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_book_category_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_book_category_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_book_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_book_category_tid']['vocabulary'] = 'reading_category';
  $handler->display->display_options['filters']['field_book_category_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_book_category_tid']['error_message'] = 1;
  /* Filter criterion: Content: Authors (field_book_author) */
  $handler->display->display_options['filters']['field_book_author_tid']['id'] = 'field_book_author_tid';
  $handler->display->display_options['filters']['field_book_author_tid']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['filters']['field_book_author_tid']['field'] = 'field_book_author_tid';
  $handler->display->display_options['filters']['field_book_author_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_author_tid']['expose']['operator_id'] = 'field_book_author_tid_op';
  $handler->display->display_options['filters']['field_book_author_tid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['field_book_author_tid']['expose']['operator'] = 'field_book_author_tid_op';
  $handler->display->display_options['filters']['field_book_author_tid']['expose']['identifier'] = 'field_book_author_tid';
  $handler->display->display_options['filters']['field_book_author_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_book_author_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_book_author_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_book_author_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_book_author_tid']['vocabulary'] = 'book_authors';
  $handler->display->display_options['filters']['field_book_author_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_book_author_tid']['error_message'] = 1;

  /* Display: All books */
  $handler = $view->new_display('page', 'All books', 'page');
  $handler->display->display_options['path'] = 'allbooks';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All Books';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block my books */
  $handler = $view->new_display('block', 'Block my books', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My books';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Authors */
  $handler->display->display_options['fields']['field_book_author']['id'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['fields']['field_book_author']['field'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_author']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_book_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_author']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_author']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_book_author']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_book_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_book_author']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_book_author']['field_api_classes'] = 0;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_book_category']['id'] = 'field_book_category';
  $handler->display->display_options['fields']['field_book_category']['table'] = 'field_data_field_book_category';
  $handler->display->display_options['fields']['field_book_category']['field'] = 'field_book_category';
  $handler->display->display_options['fields']['field_book_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_category']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_book_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_category']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_book_category']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_book_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_book_category']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_book_category']['field_api_classes'] = 0;
  /* Field: Content: Plan reading until */
  $handler->display->display_options['fields']['field_book_read']['id'] = 'field_book_read';
  $handler->display->display_options['fields']['field_book_read']['table'] = 'field_data_field_book_read';
  $handler->display->display_options['fields']['field_book_read']['field'] = 'field_book_read';
  $handler->display->display_options['fields']['field_book_read']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_read']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_read']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_read']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_read']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_book_read']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_read']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_read']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_read']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_book_read']['settings'] = array(
    'interval' => '2',
  );
  $handler->display->display_options['fields']['field_book_read']['field_api_classes'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Actions';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: My books */
  $handler = $view->new_display('page', 'My books', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Books';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['path'] = 'allbooks/mybooks';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Books';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['all_books'] = array(
    t('Master'),
    t('All Books'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('author'),
    t('Title'),
    t('Authors'),
    t('Category'),
    t('Plan reading until'),
    t('Nid'),
    t('All'),
    t('Author'),
    t('All books'),
    t('Block my books'),
    t('My books'),
    t('Actions'),
    t('edit'),
    t('node/[nid]/edit'),
    t('My Books'),
  );
  $export['all_books'] = $view;

  return $export;
}
