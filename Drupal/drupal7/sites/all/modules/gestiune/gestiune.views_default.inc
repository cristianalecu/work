<?php
/**
 * @file
 * gestiune.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gestiune_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'niruri';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'NIR-uri';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'NIR-uri';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mai multe';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicare';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Resetează';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortare după';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendent';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pe pagină';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Toate -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Decalaj';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primul';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'următor ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_nr_document' => 'field_nr_document',
    'field_data_document' => 'field_data_document',
    'field_supplier' => 'field_supplier',
  );
  $handler->display->display_options['style_options']['default'] = 'field_data_document';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nr_document' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_data_document' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_supplier' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Cap: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<h2><a href="node/add/nir">Adauga NIR</a></h2>
';
  /* Relaţie: Conţinut: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Câmp: Conţinut: Titlu */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Câmp: Node: Nr. Document */
  $handler->display->display_options['fields']['field_nr_document']['id'] = 'field_nr_document';
  $handler->display->display_options['fields']['field_nr_document']['table'] = 'field_data_field_nr_document';
  $handler->display->display_options['fields']['field_nr_document']['field'] = 'field_nr_document';
  $handler->display->display_options['fields']['field_nr_document']['label'] = 'Nr. Doc';
  /* Câmp: Node: Data Document */
  $handler->display->display_options['fields']['field_data_document']['id'] = 'field_data_document';
  $handler->display->display_options['fields']['field_data_document']['table'] = 'field_data_field_data_document';
  $handler->display->display_options['fields']['field_data_document']['field'] = 'field_data_document';
  $handler->display->display_options['fields']['field_data_document']['label'] = 'Dată';
  $handler->display->display_options['fields']['field_data_document']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Câmp: Node: Furnizor */
  $handler->display->display_options['fields']['field_supplier']['id'] = 'field_supplier';
  $handler->display->display_options['fields']['field_supplier']['table'] = 'field_data_field_supplier';
  $handler->display->display_options['fields']['field_supplier']['field'] = 'field_supplier';
  $handler->display->display_options['fields']['field_supplier']['type'] = 'taxonomy_term_reference_plain';
  /* Criteriu de sortare: Conţinut: Data postării */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criteriu de filtrare: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criteriu de filtrare: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nir' => 'nir',
  );
  /* Criteriu de filtrare: Utilizator: Actual */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Criteriu de filtrare: Data: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['value']['value'] = '2016-12-06';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'first day of January';
  $handler->display->display_options['filters']['date_filter']['default_to_date'] = 'last day of December';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_data_document.field_data_document_value' => 'field_data_field_data_document.field_data_document_value',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nir-uri';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'NIR-uri';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $translatables['niruri'] = array(
    t('Master'),
    t('NIR-uri'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Ascendent'),
    t('Desc'),
    t('Elemente pe pagină'),
    t('- Toate -'),
    t('Decalaj'),
    t('« primul'),
    t('‹ anterior'),
    t('următor ›'),
    t('ultima »'),
    t('autor'),
    t('Titlu'),
    t('Nr. Doc'),
    t('Dată'),
    t('Furnizor'),
    t('Page'),
  );
  $export['niruri'] = $view;

  return $export;
}
