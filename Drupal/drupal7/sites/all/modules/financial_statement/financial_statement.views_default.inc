<?php
/**
 * @file
 * financial_statement.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function financial_statement_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'assets_and_liabilities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Assets and Liabilities';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Assets and Liabilities';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_budget_rec_amount']['id'] = 'field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['table'] = 'field_data_field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['field'] = 'field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['label'] = 'Amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'uid';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '!1';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '!2';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_1']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '!3';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing_2']['hide_alter_empty'] = 0;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Incomes';
  $handler->display->display_options['fields']['view']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['view']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['view']['view'] = 'budget_incomes';
  $handler->display->display_options['fields']['view']['display'] = 'page';
  $handler->display->display_options['fields']['view']['arguments'] = '[nothing],[nothing_1],[nothing_2],[nid]';
  $handler->display->display_options['fields']['view']['query_aggregation'] = 0;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_budget_rec_amount_value']['id'] = 'field_budget_rec_amount_value';
  $handler->display->display_options['sorts']['field_budget_rec_amount_value']['table'] = 'field_data_field_budget_rec_amount';
  $handler->display->display_options['sorts']['field_budget_rec_amount_value']['field'] = 'field_budget_rec_amount_value';
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
  /* Contextual filter: Content: Updated year */
  $handler->display->display_options['arguments']['changed_year']['id'] = 'changed_year';
  $handler->display->display_options['arguments']['changed_year']['table'] = 'node';
  $handler->display->display_options['arguments']['changed_year']['field'] = 'changed_year';
  $handler->display->display_options['arguments']['changed_year']['title_enable'] = 1;
  $handler->display->display_options['arguments']['changed_year']['title'] = 'Assets and Liabilities %2';
  $handler->display->display_options['arguments']['changed_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['changed_year']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['changed_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['changed_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['changed_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Updated month */
  $handler->display->display_options['arguments']['changed_month']['id'] = 'changed_month';
  $handler->display->display_options['arguments']['changed_month']['table'] = 'node';
  $handler->display->display_options['arguments']['changed_month']['field'] = 'changed_month';
  $handler->display->display_options['arguments']['changed_month']['title_enable'] = 1;
  $handler->display->display_options['arguments']['changed_month']['title'] = 'Assets and Liabilities %3/%2';
  $handler->display->display_options['arguments']['changed_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['changed_month']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['changed_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['changed_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['changed_month']['summary_options']['items_per_page'] = '25';
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
    'asset' => 'asset',
  );
  /* Filter criterion: Content: Sold (field_asset_sold) */
  $handler->display->display_options['filters']['field_asset_sold_value']['id'] = 'field_asset_sold_value';
  $handler->display->display_options['filters']['field_asset_sold_value']['table'] = 'field_data_field_asset_sold';
  $handler->display->display_options['filters']['field_asset_sold_value']['field'] = 'field_asset_sold_value';
  $handler->display->display_options['filters']['field_asset_sold_value']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['operator_id'] = 'field_asset_sold_value_op';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['operator'] = 'field_asset_sold_value_op';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['identifier'] = 'field_asset_sold_value';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['reduce'] = 0;

  /* Display: Assets and Liabilities */
  $handler = $view->new_display('page', 'Assets and Liabilities', 'page');
  $handler->display->display_options['path'] = 'assets-and-liabilities';
  $handler->display->display_options['menu']['title'] = 'Assets and Liabilities';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Active Assets */
  $handler = $view->new_display('references', 'Active Assets', 'references_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'asset' => 'asset',
  );
  /* Filter criterion: Content: Sold (field_asset_sold) */
  $handler->display->display_options['filters']['field_asset_sold_value']['id'] = 'field_asset_sold_value';
  $handler->display->display_options['filters']['field_asset_sold_value']['table'] = 'field_data_field_asset_sold';
  $handler->display->display_options['filters']['field_asset_sold_value']['field'] = 'field_asset_sold_value';
  $handler->display->display_options['filters']['field_asset_sold_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['operator_id'] = 'field_asset_sold_value_op';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['operator'] = 'field_asset_sold_value_op';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['identifier'] = 'field_asset_sold_value';
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_asset_sold_value']['expose']['reduce'] = 0;
  $translatables['assets_and_liabilities'] = array(
    t('Master'),
    t('Assets and Liabilities'),
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
    t('Nid'),
    t('Amount'),
    t('uid'),
    t('!1'),
    t('Custom text'),
    t('!2'),
    t('!3'),
    t('Incomes'),
    t('All'),
    t('Assets and Liabilities %2'),
    t('Assets and Liabilities %3/%2'),
    t('Status'),
    t('Active Assets'),
  );
  $export['assets_and_liabilities'] = $view;

  $view = new view;
  $view->name = 'budget_incomes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Budget Incomes';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Budget Incomes';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_budget_rec_amount' => 'field_budget_rec_amount',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'field_budget_rec_amount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
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
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Reason';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_budget_rec_amount']['id'] = 'field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['table'] = 'field_data_field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['field'] = 'field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['label'] = 'Amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['hide_alter_empty'] = 0;
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
  /* Contextual filter: Content: Updated year */
  $handler->display->display_options['arguments']['changed_year']['id'] = 'changed_year';
  $handler->display->display_options['arguments']['changed_year']['table'] = 'node';
  $handler->display->display_options['arguments']['changed_year']['field'] = 'changed_year';
  $handler->display->display_options['arguments']['changed_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['changed_year']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['changed_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['changed_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['changed_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Updated month */
  $handler->display->display_options['arguments']['changed_month']['id'] = 'changed_month';
  $handler->display->display_options['arguments']['changed_month']['table'] = 'node';
  $handler->display->display_options['arguments']['changed_month']['field'] = 'changed_month';
  $handler->display->display_options['arguments']['changed_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['changed_month']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['changed_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['changed_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['changed_month']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: For an Asset (field_ref_asset) */
  $handler->display->display_options['arguments']['field_ref_asset_nid']['id'] = 'field_ref_asset_nid';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['table'] = 'field_data_field_ref_asset';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['field'] = 'field_ref_asset_nid';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_ref_asset_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_ref_asset_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ref_asset_nid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'budget_record' => 'budget_record',
  );

  /* Display: Incomes  */
  $handler = $view->new_display('page', 'Incomes ', 'page');
  $handler->display->display_options['path'] = 'budget-incomes';

  /* Display: Incomes Sum */
  $handler = $view->new_display('page', 'Incomes Sum', 'page_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Reason';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_budget_rec_amount']['id'] = 'field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['table'] = 'field_data_field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['field'] = 'field_budget_rec_amount';
  $handler->display->display_options['fields']['field_budget_rec_amount']['label'] = '';
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_rec_amount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_budget_rec_amount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_budget_rec_amount']['hide_alter_empty'] = 0;
  $handler->display->display_options['path'] = 'incomes_sum';
  $translatables['budget_incomes'] = array(
    t('Master'),
    t('Budget Incomes'),
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
    t('Reason'),
    t('Amount'),
    t('All'),
    t('Incomes '),
    t('Incomes Sum'),
  );
  $export['budget_incomes'] = $view;

  $view = new view;
  $view->name = 'budget_periods';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Budget Periods';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Budget Periods';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'changed' => 'changed',
    'changed_1' => 'changed_1',
    'changed_2' => 'changed_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'changed_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'changed_2' => array(
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
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: AVG(Content: Updated date) */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['group_type'] = 'avg';
  $handler->display->display_options['fields']['changed']['label'] = 'Year';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['path'] = 'assets-and-liabilities/!1/[changed]';
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'node';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['label'] = 'Month Nr';
  $handler->display->display_options['fields']['changed_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'm';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_2']['id'] = 'changed_2';
  $handler->display->display_options['fields']['changed_2']['table'] = 'node';
  $handler->display->display_options['fields']['changed_2']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_2']['label'] = 'Month';
  $handler->display->display_options['fields']['changed_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['changed_2']['alter']['path'] = 'assets-and-liabilities/!1/[changed]/[changed_1]';
  $handler->display->display_options['fields']['changed_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed_2']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['changed_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed_2']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_2']['custom_date_format'] = 'Y F';
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
    'budget_record' => 'budget_record',
    'budget_payment' => 'budget_payment',
  );

  /* Display: Periods */
  $handler = $view->new_display('page', 'Periods', 'page');
  $handler->display->display_options['path'] = 'budget-periods';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Periods';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['budget_periods'] = array(
    t('Master'),
    t('Budget Periods'),
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
    t('Year'),
    t('assets-and-liabilities/!1/[changed]'),
    t('Month Nr'),
    t('Month'),
    t('assets-and-liabilities/!1/[changed]/[changed_1]'),
    t('All'),
    t('Periods'),
  );
  $export['budget_periods'] = $view;

  return $export;
}
