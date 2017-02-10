<?php
/**
 * @file
 * _thiswebsite.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function _thiswebsite_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'lista_articole';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Lista articole';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Noutăţi Ştiri';
  $handler->display->display_options['use_more_text'] = 'mai multe';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Resetează';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortare după';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Nici un articol în listă';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Câmp: Conţinut: Titlu */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Câmp: Conţinut: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/node/[nid]">Detalii</a> | ';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Câmp: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['totalcount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['totalcount']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['totalcount']['format_plural'] = 0;
  $handler->display->display_options['fields']['totalcount']['suffix'] = ' accesări | ';
  /* Câmp: Conţinut: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Conţinut: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';

  /* Display: News */
  $handler = $view->new_display('page', 'News', 'page');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    619 => '619',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ştiri';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Acte */
  $handler = $view->new_display('page', 'Acte', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Acte de înfiinţare';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    637 => '637',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'acteinfiintare';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Acte de înfiinţare';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-baroul';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Asistenţa juridică */
  $handler = $view->new_display('page', 'Asistenţa juridică', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Asistenţa juridică';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    638 => '638',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'asistentajuridica';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Asistenţa juridică';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-baroul';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Comunicate */
  $handler = $view->new_display('page', 'Comunicate', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Comunicate';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    620 => '620',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'comunicate';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Comunicate';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-noutati';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Comunicări Barouri */
  $handler = $view->new_display('page', 'Comunicări Barouri', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'UNBR Comunicări Barouri';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    639 => '639',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'comunicaribarouri';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Comunicări Barouri';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-baroul';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Legislaţie */
  $handler = $view->new_display('page', 'Legislaţie', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Legislaţie';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    622 => '622',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'legislaţie';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Legislaţie';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-noutati';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Presa despre avocaţi */
  $handler = $view->new_display('page', 'Presa despre avocaţi', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Presa despre avocaţi';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    640 => '640',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'presadespreavocati';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Presa despre avocaţi';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-noutati';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Juristprudenţa profesională */
  $handler = $view->new_display('page', 'Juristprudenţa profesională', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Juristprudenţa profesională';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    641 => '641',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'juristprudenta';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Juristprudenţa profesională';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cariera';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Avocaţii europeni */
  $handler = $view->new_display('page', 'Avocaţii europeni', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Avocaţii europeni';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    642 => '642',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'avocatieuropeni';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Avocaţii europeni';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cariera';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Actele organelor profesiei */
  $handler = $view->new_display('page', 'Actele organelor profesiei', 'page_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Actele organelor profesiei';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol' => 'articol',
  );
  /* Filter criterion: Conţinut: Categoria (field_articol_categ) */
  $handler->display->display_options['filters']['field_articol_categ_tid']['id'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['table'] = 'field_data_field_articol_categ';
  $handler->display->display_options['filters']['field_articol_categ_tid']['field'] = 'field_articol_categ_tid';
  $handler->display->display_options['filters']['field_articol_categ_tid']['value'] = array(
    643 => '643',
  );
  $handler->display->display_options['filters']['field_articol_categ_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_articol_categ_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_articol_categ_tid']['vocabulary'] = '_tiri';
  $handler->display->display_options['path'] = 'acteleorganelor';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Actele organelor profesiei';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-cariera';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['lista_articole'] = array(
    t('Master'),
    t('Noutăţi Ştiri'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Nici un articol în listă'),
    t('<a href="/node/[nid]">Detalii</a> | '),
    t('.'),
    t(','),
    t(' accesări | '),
    t('News'),
    t('Acte'),
    t('Acte de înfiinţare'),
    t('Asistenţa juridică'),
    t('Comunicate'),
    t('Comunicări Barouri'),
    t('UNBR Comunicări Barouri'),
    t('Legislaţie'),
    t('Presa despre avocaţi'),
    t('Juristprudenţa profesională'),
    t('Avocaţii europeni'),
    t('Actele organelor profesiei'),
  );
  $export['lista_articole'] = $view;

  return $export;
}
