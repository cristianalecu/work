<?php
/**
 * @file
 * objective_planning.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function objective_planning_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'user_objectives';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'User Objectives';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My objectives';
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
    'field_obj_milestone' => 'field_obj_milestone',
  );
  $handler->display->display_options['style_options']['default'] = 'field_obj_milestone';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_obj_milestone' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
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
  /* Field: Content: Milestone */
  $handler->display->display_options['fields']['field_obj_milestone']['id'] = 'field_obj_milestone';
  $handler->display->display_options['fields']['field_obj_milestone']['table'] = 'field_data_field_obj_milestone';
  $handler->display->display_options['fields']['field_obj_milestone']['field'] = 'field_obj_milestone';
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_obj_milestone']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_obj_milestone']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_obj_milestone']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_obj_milestone']['field_api_classes'] = 0;
  /* Sort criterion: Content: Milestone (field_obj_milestone) */
  $handler->display->display_options['sorts']['field_obj_milestone_value']['id'] = 'field_obj_milestone_value';
  $handler->display->display_options['sorts']['field_obj_milestone_value']['table'] = 'field_data_field_obj_milestone';
  $handler->display->display_options['sorts']['field_obj_milestone_value']['field'] = 'field_obj_milestone_value';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 1;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
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
    'objective' => 'objective',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'userobjectives';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Objectives';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['user_objectives'] = array(
    t('Master'),
    t('My objectives'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Title'),
    t('Milestone'),
    t('All'),
    t('Page'),
    t('Block'),
  );
  $export['user_objectives'] = $view;

  return $export;
}
