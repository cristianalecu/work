<?php
/**
 * @file
 * _thiswebsite.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function _thiswebsite_user_default_roles() {
  $roles = array();

  // Exported role: manager.
  $roles['manager'] = array(
    'name' => 'manager',
    'weight' => '3',
  );

  // Exported role: operator.
  $roles['operator'] = array(
    'name' => 'operator',
    'weight' => '4',
  );

  return $roles;
}
