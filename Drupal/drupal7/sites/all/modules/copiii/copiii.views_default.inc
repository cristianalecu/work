<?php
/**
 * @file
 * copiii.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function copiii_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'comentarii_abuzive';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Comentarii Abuzive';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Comentarii Abuzive';
  $handler->display->display_options['use_more_text'] = 'mai multe';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Resetează';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortare după';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'subject' => 'subject',
    'comment_body' => 'comment_body',
    'name' => 'name',
    'timestamp' => 'timestamp',
    'edit_comment' => 'edit_comment',
    'delete_comment' => 'edit_comment',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'subject' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_body' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_comment' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relaţie: Comentariu: Conţinut */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 1;
  /* Relaţie: Flags: abuse_comment */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'comment';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'abuse_comment';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Câmp: Comentariu: Titlu */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['subject']['link_to_comment'] = 1;
  $handler->display->display_options['fields']['subject']['link_to_node'] = 0;
  /* Câmp: Comentariu: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = 'Comentariu';
  $handler->display->display_options['fields']['comment_body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['comment_body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['comment_body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['comment_body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['comment_body']['field_api_classes'] = 0;
  /* Câmp: Comentariu: Autor */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Autor comentariu';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  /* Câmp: Flags: Flagged time */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flag_content';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Data raportării';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  /* Câmp: Comentariu: Edit link */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['label'] = 'Acţiuni';
  $handler->display->display_options['fields']['edit_comment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_comment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_comment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_comment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_comment']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['edit_comment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_comment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_comment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_comment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_comment']['link_to_node'] = 0;
  $handler->display->display_options['fields']['edit_comment']['destination'] = 0;
  /* Câmp: Comentariu: Delete link */
  $handler->display->display_options['fields']['delete_comment']['id'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['delete_comment']['field'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['label'] = '';
  $handler->display->display_options['fields']['delete_comment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_comment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_comment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_comment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_comment']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_comment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_comment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_comment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delete_comment']['link_to_node'] = 0;
  /* Sort criterion: Comentariu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Comentariu: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 0;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'comentarii-abuzive';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Abuz Comentarii';
  $translatables['comentarii_abuzive'] = array(
    t('Master'),
    t('Comentarii Abuzive'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Conţinut'),
    t('flag'),
    t('Titlu'),
    t('Comentariu'),
    t('Autor comentariu'),
    t('Data raportării'),
    t('Acţiuni'),
    t('Page'),
  );
  $export['comentarii_abuzive'] = $view;

  $view = new view;
  $view->name = 'comentariile_mele';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Comentariile mele';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Comentariile mele';
  $handler->display->display_options['use_more_text'] = 'mai multe';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Resetează';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortare după';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Nu aţi scris comentarii cât timp aţi fost autentificat (logat).';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relaţie: Comentariu: Conţinut */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 1;
  /* Relaţie: Comentariu: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Câmp: Conţinut: Titlu */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Pagina';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Câmp: Comentariu: Titlu */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject']['link_to_comment'] = 1;
  /* Câmp: Comentariu: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = '';
  $handler->display->display_options['fields']['comment_body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['comment_body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['comment_body']['field_api_classes'] = 0;
  /* Sort criterion: Comentariu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 0;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;
  /* Filter criterion: Utilizator: Actual */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'comentariile-mele';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Comentariile mele';
  $translatables['comentariile_mele'] = array(
    t('Master'),
    t('Comentariile mele'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Nu aţi scris comentarii cât timp aţi fost autentificat (logat).'),
    t('Conţinut'),
    t('author'),
    t('Pagina'),
    t('Page'),
  );
  $export['comentariile_mele'] = $view;

  $view = new view;
  $view->name = 'panse_in_categorie';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Panse in categorie';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Planşe';
  $handler->display->display_options['use_more_text'] = 'mai multe';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Resetează';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortare după';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Câmp: Conţinut: Titlu */
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
  /* Câmp: Conţinut: Imagine */
  $handler->display->display_options['fields']['field_plansa_imagine']['id'] = 'field_plansa_imagine';
  $handler->display->display_options['fields']['field_plansa_imagine']['table'] = 'field_data_field_plansa_imagine';
  $handler->display->display_options['fields']['field_plansa_imagine']['field'] = 'field_plansa_imagine';
  $handler->display->display_options['fields']['field_plansa_imagine']['label'] = '';
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_plansa_imagine']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_plansa_imagine']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_plansa_imagine']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_plansa_imagine']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_plansa_imagine']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_plansa_imagine']['field_api_classes'] = 0;
  /* Sort criterion: Conţinut: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Conţinut: Caregoria (field_plansa_categ) */
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['id'] = 'field_plansa_categ_tid';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['table'] = 'field_data_field_plansa_categ';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['field'] = 'field_plansa_categ_tid';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['breadcrumb_enable'] = 1;
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['validate_options']['vocabularies'] = array(
    'planse' => 'planse',
  );
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_plansa_categ_tid']['not'] = 0;
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
    'plan_' => 'plan_',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'planse/categorie';
  $translatables['panse_in_categorie'] = array(
    t('Master'),
    t('Planşe'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Toate'),
    t('Page'),
  );
  $export['panse_in_categorie'] = $view;

  $view = new view;
  $view->name = 'planse';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Planşe de colorat';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Planşe de colorat';
  $handler->display->display_options['use_more_text'] = 'mai multe';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Resetează';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortare după';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Câmp: Termen taxonomie: ID termen */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Câmp: Termen taxonomie: Imagine */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['label'] = '';
  $handler->display->display_options['fields']['field_term_image']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_term_image']['alter']['text'] = '<a href="/planse/categorie/[tid]">[field_term_image]</a>';
  $handler->display->display_options['fields']['field_term_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_term_image']['field_api_classes'] = 0;
  /* Filter criterion: Vocabular taxonomie: Nume maşină */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'planse' => 'planse',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'categoriiplanse';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Planşe de colorat';

  /* Display: Bloc */
  $handler = $view->new_display('block', 'Bloc', 'block_1');
  $translatables['planse'] = array(
    t('Master'),
    t('Planşe de colorat'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t('<a href="/planse/categorie/[tid]">[field_term_image]</a>'),
    t('Page'),
    t('Bloc'),
  );
  $export['planse'] = $view;

  $view = new view;
  $view->name = 'unde_mergem_cu_copiii';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Unde mergem cu copiii';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Unde mergem cu copiii';
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
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'comment_count' => 'comment_count',
    'comments_link' => 'comments_link',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Subsol: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  /* Relaţie: Flags: flag_util counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'flag_util';
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
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'readmore_inline';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
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
  $handler->display->display_options['fields']['totalcount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['totalcount']['element_wrapper_class'] = 'accesari_inline';
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['totalcount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = 1;
  $handler->display->display_options['fields']['totalcount']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['format_plural'] = 0;
  $handler->display->display_options['fields']['totalcount']['suffix'] = ' accesari | ';
  /* Câmp: Conţinut: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Câmp: Conţinut: Număr comentarii */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<a href="/ro/node/[nid_1]#comments" class="comentarii_inline">[comment_count] comentarii | </a>';
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  /* Câmp: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['count']['element_wrapper_class'] = 'utile_inline';
  $handler->display->display_options['fields']['count']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['count']['empty_zero'] = 1;
  $handler->display->display_options['fields']['count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['count']['format_plural'] = 0;
  $handler->display->display_options['fields']['count']['suffix'] = ' util';
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
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Conţinut: Data actualizării */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Conţinut: Publicat */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conţinut: Tip */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'articol_unde_mergem' => 'articol_unde_mergem',
  );
  $handler->display->display_options['filters']['type']['group'] = '1';

  /* Display: Blog Page */
  $handler = $view->new_display('page', 'Blog Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'readmore_inline';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
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
  $handler->display->display_options['fields']['totalcount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['totalcount']['element_wrapper_class'] = 'accesari_inline';
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['totalcount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = 1;
  $handler->display->display_options['fields']['totalcount']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['format_plural'] = 0;
  $handler->display->display_options['fields']['totalcount']['suffix'] = ' accesari | ';
  /* Câmp: Conţinut: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Câmp: Conţinut: Număr comentarii */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<a href="/ro/node/[nid_1]#comments" class="comentarii_inline">[comment_count] comentarii | </a>';
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  /* Câmp: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = '';
  $handler->display->display_options['fields']['count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['count']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['count']['element_wrapper_class'] = 'utile_inline';
  $handler->display->display_options['fields']['count']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['count']['empty_zero'] = 1;
  $handler->display->display_options['fields']['count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['count']['format_plural'] = 0;
  $handler->display->display_options['fields']['count']['suffix'] = ' util';
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
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 1;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1200',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'undemergem';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Unde mergem cu copiii';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Top articole Blog */
  $handler = $view->new_display('block', 'Top articole Blog', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Articole recente';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Subsol: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/ro/blog">Toate articolele</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  $translatables['unde_mergem_cu_copiii'] = array(
    t('Master'),
    t('Unde mergem cu copiii'),
    t('mai multe'),
    t('Aplicare'),
    t('Resetează'),
    t('Sortare după'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('counter'),
    t('<a href="/node/[nid]">Detalii</a> | '),
    t('.'),
    t(','),
    t(' accesari | '),
    t('<a href="/ro/node/[nid_1]#comments" class="comentarii_inline">[comment_count] comentarii | </a>'),
    t(' util'),
    t('Blog Page'),
    t('Top articole Blog'),
    t('Articole recente'),
    t('<a href="/ro/blog">Toate articolele</a>'),
  );
  $export['unde_mergem_cu_copiii'] = $view;

  return $export;
}
