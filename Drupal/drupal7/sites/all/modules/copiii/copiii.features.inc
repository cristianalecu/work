<?php
/**
 * @file
 * copiii.features.inc
 */

/**
 * Implements hook_views_api().
 */
function copiii_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function copiii_flag_default_flags() {
  $flags = array();
  // Exported flag: "Comentariu abuziv".
  $flags['abuse_comment'] = array(
    'content_type' => 'comment',
    'title' => 'Comentariu abuziv',
    'global' => 0,
    'types' => array(
      0 => 'article',
    ),
    'flag_short' => ' . . Ofense-injurii',
    'flag_long' => 'Marchează aceast comentariu ca ofensator sau cu injurii',
    'flag_message' => 'Marcat ca ofense-injurii',
    'unflag_short' => ' . . Scoate marcaj ofense',
    'unflag_long' => 'Scoate marcajul de ofense de pa aceast comentariu',
    'unflag_message' => 'Marcajul de ofesă a fost scos',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
        2 => '4',
        3 => '5',
      ),
      'unflag' => array(
        0 => '2',
        1 => '3',
        2 => '4',
        3 => '5',
      ),
    ),
    'access_author' => '',
    'show_on_comment' => 1,
    'module' => 'copiii',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "User Abuse".
  $flags['abuse_user'] = array(
    'content_type' => 'user',
    'title' => 'User Abuse',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Report User',
    'flag_long' => 'Report this user as offensive.',
    'flag_message' => '',
    'unflag_short' => 'Remove Report',
    'unflag_long' => 'Remove your report about this user.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_profile' => TRUE,
    'access_uid' => '',
    'events' => array(
      0 => 'flag',
      1 => 'unflag',
    ),
    'flag_confirmation' => 'Are you sure you want to report this user as offensive?',
    'unflag_confirmation' => 'Are you sure you want to remove your report of this user?',
    'reset_short' => 'Reset flags',
    'reset_long' => 'Reset all flags on this user',
    'reset_confirmation' => 'Are you sure you want to reset all flags on this user?',
    'status' => FALSE,
    'show_on_teaser' => FALSE,
    'locked' => array(
      0 => 'name',
    ),
    'module' => 'copiii',
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_image_default_styles().
 */
function copiii_image_default_styles() {
  $styles = array();

  // Exported image style: width600
  $styles['width600'] = array(
    'name' => 'width600',
    'effects' => array(
      1 => array(
        'label' => 'Scalare',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '600',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function copiii_node_info() {
  $items = array(
    'articol_unde_mergem' => array(
      'name' => t('Articol unde mergem'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'coloreaza_online' => array(
      'name' => t('Coloreaza Online'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'plan_' => array(
      'name' => t('Planşă'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function copiii_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Detalii personale",
    "weight" : "0",
    "data" : { "registration" : 0 }
  }');
  return $items;
}
