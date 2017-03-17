<?php

/**
 * @file
 * Administrative page callbacks for the game_war module.
 */

/**
 * Form builder for the war game atac editing form.
 *
 * @ingroup forms
 * @see game_war_form_atac_submit()
 * @see game_war_form_ataca_validate()
 */
function game_war_form_atac($form, &$form_state, $edit = array(), $usr = NULL) {
global $user;
global $war_data;
global $game_settings;

	$uid = $user->uid;
	if($usr == null)
	{
		$usr = $GLOBALS['_GET']['q'];
		$ux = explode("/", $usr);
		$usr = $ux[2];
	}

	if (!isset($form_state['war_atac'])) {
		$war_atac = is_object($edit) ? $edit : (object) $edit;
		$form_state['war_atac'] = $war_atac;
	}
	else {
		$war_atac = $form_state['war_atac'];
	}

	// @todo Legacy support. Modules are encouraged to access the entity using
	//   $form_state. Remove in Drupal 8.
	$form['#war_atac'] = $form_state['war_atac'];

	$form['tab_atac'] = array(
			'#type' => 'fieldset',
			'#title' => t('Atac'),
			'#collapsible' => FALSE,
	);
	$usr_gamedata = game_war_get_userdata($usr);
	game_war_get_userdata($uid);
	game_war_get_gamesettings();
	$usrx = user_load($usr, FALSE);
	$prefix = '<table class="sticky-table"><tbody><tr><td colspan=3 style="text-align: center;">' . $usr_gamedata['name'] . '</td></tr>';
	$poza = '<img style="max-width:98px;" src="' . $GLOBALS['base_url'] . '/defimg.jpg">';
	if(!isset($usrx->picture))
	{
		$account = new StdClass();
		$account->picture = $usrx->picture;
		$account->uid = $usrx->uid;
		$account->name = $usrx->name;
		$param = array('account' => $account);
		template_preprocess_user_picture($param);
		$poza = $param['user_picture'];
	}
	$atac = '';
	for($i = 0; $i<10; $i++) {
		if(($i+1)*$game_settings['nivel_grad'] < $usr_gamedata['bonus_atac'])
			$atac .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/silver_star_medal.png">';
		else
			$atac .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/empty_star_medal.png">';
	}
	$aparare = '';
	for($i = 0; $i<10; $i++) {
		if(($i+1)*$game_settings['nivel_grad'] < $usr_gamedata['bonus_aparare'])
			$aparare .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/bronze_star_medal.png">';
		else
			$aparare .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/empty_star_medal.png">';
	}
	$pericol = intval($usr_gamedata['bonus_atac'] / $game_settings['nivel_pericol']) . ' <img style="max-width:30px;" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/star-medal.png" title="0 Atac">' .
			intval($usr_gamedata['bonus_aparare'] / $game_settings['nivel_pericol']) . ' <img style="max-width:50px;" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/star_sheriff.png" title="0 Aparare">';
	$prefix .= '<tr><td rowspan=7>' . $poza . '</td><td>' . 'Cazarma:' . '</td><td><b>' . $usr_gamedata['soldati'] . '</b> ' . t('Soldati') . '</td></tr>';
	$prefix .= '<tr><td>' . 'Bani:' . '</td><td><b>' . $usr_gamedata['bani'] . '</b> ' . $game_settings['moneda'] . '</td></tr>';
	$prefix .= '<tr><td>' . 'Atac:' . '</td><td>' . $atac . '</td></tr>';
	$prefix .= '<tr><td>' . 'Aparare:' . '</td><td>' . $aparare . '</td></tr>';
	$prefix .= '<tr><td>' . 'Pericol:' . '</td><td>' . $pericol . '</td></tr>';
	$suffix = '</tbody></table>' ;	
	
	$sSql = "select count(*) cnt from {user_lupte} where uid = $uid and uid2 = $usr";
	$result = db_query($sSql);
	foreach ($result as $rs)
	{
		$lupteazi = $rs->cnt;
	}
	if($lupteazi >= 7)
		$suffix .= "Poti ataca de maxim 7 ori pe zi un jucator";
	else if ($usr_gamedata['soldati'] > 3 * $war_data['soldati'])
		$suffix .= "Nu poti ataca un jucator care are mai mult de 3 ori numarul tau de soldati ";
	else if ($usr_gamedata['soldati'] < ($war_data['soldati'] / 3))
		$suffix .= "Nu poti ataca un jucator care are mai putin de 1/3 din soldatii tai ";
	else 
	{
		$atac_submut = array(
				'#name' => 'date_atace',
				'#type' => 'submit',
				'#value' => t('Ataca'),
				'#suffix' => "<br>",
		);
	}
	$form['tab_atac']['atac_table'] = array(
			'#type' => 'hidden',
			'#value' => 1,
			'#prefix' => $prefix,
			'#suffix' => $suffix,
	);
	if(isset($atac_submut))
	{
		$form['tab_atac']['atacuri'] = array(
				'#name' => 'atacuri',
				'#type' => 'textfield',
				'#title' => t('Atacuri Folosite'),
				'#maxlength' => 2,
				'#size' => 2,
				'#required' => FALSE,
				'#default_value' => '10',
    		    '#description' => 'Cate atacuri trimiteti. Maxim 10. Mai aveti ' . $war_data['atacuri'],
				
		);
		$form['tab_atac']['submit'] = $atac_submut;
	}

	$form['#validate'][] = 'game_war_form_atac_validate';

	return $form;
}

/**
 * Form validation handler for game_war_form_atac().
 *
 * Makes sure that the entered values are valid.
 *
 * @see game_war_form_atac()
 * @see game_war_form_atac_submit()
 */
function game_war_form_atac_validate($form, &$form_state) {
	// During the deletion there is no 'machine_name' key
	if (isset($form_state['values']['machine_name'])) {
		// Do not allow machine names to conflict with taxonomy path arguments.
		$machine_name = $form_state['values']['machine_name'];
		$disallowed = array('add', 'list');
		if (in_array($machine_name, $disallowed)) {
			form_set_error('machine_name', t('The machine-readable name cannot be "add" or "list".'));
		}
	}
}

/**
 * Form submission handler for game_war_form_atac().
 *
 * @see game_war_form_atac()
 * @see game_war_form_atac_validate()
 */
function game_war_form_atac_submit($form, &$form_state) {
	global $user;
	global $game_settings;

	$uid = $user->uid;

	game_war_get_userdata();
	game_war_get_gamesettings();

	if (substr($form_state['triggering_element']['#name'],0,6) == 'cumpar') { //date_atace
		for($i = 1; $i<$form_state['values']['armacount']; $i++)
		{
			if($form_state['triggering_element']['#name'] == 'cumparma_' . $i)
			{
				$arma = explode('|', $form_state['values']['arma' . $i]);
				if($war_data['bani'] >= $arma[3])
				{
					db_query("update {user_gamedata} set bani=bani-$arma[3] where uid=$uid");
					if(isset($arma[4]))
					{
						db_query("update {user_weapons} set nr=nr+1 where uid=$uid and nid= " . $arma[0]);
					}
					else
					{
						db_query("insert into {user_weapons} values ($uid, $arma[0], $arma[1], $arma[2], 1)");
					}
				}
				else {
					drupal_set_message(t('Fonduri insuficiente'));
				}
			}
		}
		return;
	}
}

/**
 * Form builder for the war game admin editing form.
 *
 * @ingroup forms
 * @see game_war_form_admin_submit()
 * @see game_war_form_admin_validate()
 */
function game_war_form_admin($form, &$form_state, $edit = array()) {

	if (!isset($form_state['war_admin'])) {
		$war_admin = is_object($edit) ? $edit : (object) $edit;
		$form_state['war_admin'] = $war_admin;
	}
	else {
		$war_admin = $form_state['war_admin'];
	}

	$form['#war_admin'] = $form_state['war_admin'];

	$form['tab_admin'] = array(
			'#type' => 'fieldset',
			'#title' => t('Admin users'),
			'#collapsible' => FALSE,
	);
	$form['tab_admin']['atac_table'] = array(
			'#type' => 'hidden',
			'#value' => 1,
			'#prefix' => '',
			'#suffix' => '',
	);
    $form['tab_admin']['usrlevel'] = array(
				'#name' => 'usrlevel',
				'#type' => 'textfield',
				'#maxlength' => 2,
				'#size' => 2,
				'#required' => TRUE,
				'#default_value' => '0',
    		    '#description' => '1 - Add 140 users<br>2 - reset positions<br>3 - add user gamedata<br>99 - x-0 data<br>100 - reset whole game data',
	);	
    $form['tab_admin']['submit'] = array(
			'#name' => 'date_admin',
			'#type' => 'submit',
			'#value' => t('Apply'),
			'#suffix' => "<br>",
	);

	$form['#validate'][] = 'game_war_form_admin_validate';

	return $form;
}

/**
 * Form validation handler for game_war_form_admin().
 *
 * Makes sure that the entered values are valid.
 *
 * @see game_war_form_admin()
 * @see game_war_form_admin_submit()
 */
function game_war_form_admin_validate($form, &$form_state) {
	// During the deletion there is no 'machine_name' key
	if (isset($form_state['values']['machine_name'])) {
		// Do not allow machine names to conflict with taxonomy path arguments.
		$machine_name = $form_state['values']['machine_name'];
		$disallowed = array('add', 'list');
		if (in_array($machine_name, $disallowed)) {
			form_set_error('machine_name', t('The machine-readable name cannot be "add" or "list".'));
		}
	}
}

/**
 * Form submission handler for game_war_form_admin().
 *
 * @see game_war_form_admin()
 * @see game_war_form_admin_validate()
 */
function game_war_form_admin_submit($form, &$form_state) {
global $game_settings;

	game_war_get_gamesettings();
	
$names = array();
$names = array_merge($names, array('abra','basa','casa','dylan','geagum','kapak','monster','seba'));
$names = array_merge($names, array('aby','basco','casio','dyxo','gebol','karab','mosco','semi'));
$names = array_merge($names, array('aca','basta','cata','eba','geche','katan','mujake','senza'));
$names = array_merge($names, array('aci','bate','caty','ebrah','genera','kazan','murdo','senzua'));
$names = array_merge($names, array('aco','batma','cavan','edur','genius','kenta','mystry','serpa'));
$names = array_merge($names, array('acum','bau','celest','edwin','genka','kevin','nake','sfinx'));
$names = array_merge($names, array('acva','bava','celio','edy','gente','kiddo','nano','shado'));
$names = array_merge($names, array('ada','baxy','ceres','efect','geoca','kido','narcys','shery'));
$names = array_merge($names, array('adam','bazar','cesi','egipta','geonca','kiki','nashpa','shoko'));
$names = array_merge($names, array('adel','bazmy','chica','elan','geost','kilo','nasty','sici'));
$names = array_merge($names, array('adi','bazon','chilly','eldio','germano','kimoto','nemes','siro'));
$names = array_merge($names, array('adri','bazooka','chip','elektro','gerula','kindy','neutro','skilo'));
$names = array_merge($names, array('afri','bb1','chrom','element','gery','kinex','next','skin'));
$names = array_merge($names, array('agen','beast','chuck','elfy','getula','king','nexus','skorpy'));
$names = array_merge($names, array('aju','beauty','cica','elini','ghost','kitty','nicko','sky'));
$names = array_merge($names, array('aka','bebe','cio','elise','gimil','klaw','nico','slash'));
$names = array_merge($names, array('aku','beby','cioca','elixir','gingis','kombo','nikio','slow'));
$names = array_merge($names, array('albo','bed','cita','elka','ginx','kondor','nikyta','smeca'));
$names = array_merge($names, array('alco','befree','ciuca','elton','giulia','kosmo','nobo','smoke'));
$names = array_merge($names, array('ale','beib','clara','elucid','gixa','koyoty','noky','snook'));
$names = array_merge($names, array('alek','bejan','clau','elvix','glisor','kudos','nono','socol'));
$names = array_merge($names, array('alex','beka','clepto','ely','godeb','kyra','nony','sokate'));
$names = array_merge($names, array('alfa','bela','click','elyaz','gogan','lade','noro','soma'));
$names = array_merge($names, array('ali','belly','cloco','emana','golden','lagun','nuke','soria'));
$names = array_merge($names, array('alin','benga','clopo','ember','good','lalia','nymus','soyso'));
$names = array_merge($names, array('alo','benji','coca','emina','gosa','lampy','nytzo','sparta'));
$names = array_merge($names, array('alta','benky','coco','emmy','gothic','lastun','obser','spatia'));
$names = array_merge($names, array('aly','benny','conda','emper','gril','laur','octa','spectaco'));
$names = array_merge($names, array('alza','benta','cony','empire','guanta','lazary','octavy','speed'));
$names = array_merge($names, array('ama','berto','corba','empory','gymo','legia','okare','spio'));
$names = array_merge($names, array('ana','besame','corleo','enea','hack','legion','okyo','splash'));
$names = array_merge($names, array('ando','best','cosmo','enemy','hades','legs','olyga','stalke'));
$names = array_merge($names, array('andra','beto','costa','entic','hagal','leno','ombra','star'));
$names = array_merge($names, array('andy','biban','crau','entro','halo','levy','omega','state'));
$names = array_merge($names, array('angel','bibi','crazy','enturia','hamlet','lex','ona','stely'));
$names = array_merge($names, array('angi','big','creta','erase','hammer','liber','onix','sticsy'));
$names = array_merge($names, array('anima','bike','cris','erave','hamster','linko','orion','stole'));
$names = array_merge($names, array('anti','bil','crystal','eros','hapca','liryc','oscar','storm'));
$names = array_merge($names, array('anto','billy','cryxu','esperan','hapto','livit','osiris','stryke'));
$names = array_merge($names, array('api','bimbo','ctc','etern','harma','logord','ovide','style'));
$names = array_merge($names, array('apo','bitza','cubano','etiop','hateg','lordo','oxio','sugar'));
$names = array_merge($names, array('apro','bizoo','cucu','etos','haway','lovel','paku','sukar'));
$names = array_merge($names, array('aqua','bizuka','cut','eugen','helita','lovex','panca','super'));
$names = array_merge($names, array('arhi','black','cyber','eva','hello','lowe','papa','supra'));
$names = array_merge($names, array('ari','blank','cyrus','evil','helly','lucas','paptas','suter'));
$names = array_merge($names, array('arma','bloc','dacia','evol','her','lucris','parka','sylva'));
$names = array_merge($names, array('arme','blond','daemon','evry','heruve','lufer','partis','sylver'));
$names = array_merge($names, array('asalt','blood','daly','exel','hexy','luka','pasca','syrys'));
$names = array_merge($names, array('asbo','bloom','dandel','explic','heyo','lupon','paulo','szmen'));
$names = array_merge($names, array('asco','blue','dandy','extazy','horta','lyca','pereni','taika'));
$names = array_merge($names, array('aspi','bob','danger','extra','hotx','macaro','petrin','tanko'));
$names = array_merge($names, array('asto','bobby','dany','faber','howk','maceta','pica','tanto'));
$names = array_merge($names, array('aston','body','danza','fabi','hunter','macor','picar','tantoi'));
$names = array_merge($names, array('astro','bogat','dark','fake','hyper','madan','pikolo','tarabo'));
$names = array_merge($names, array('ati','boggy','darky','fakir','iacobo','madon','pikul','tatika'));
$names = array_merge($names, array('atka','bond','dary','fanfa','ibiza','madra','pirate','tatoo'));
$names = array_merge($names, array('atla','bone','david','fanny','icele','magda','piton','tavita'));
$names = array_merge($names, array('atol','boom','dazy','fantas','idol','magnum','pixel','tazzy'));
$names = array_merge($names, array('aton','boox','deadly','farm','igor','major','pocho','tedeo'));
$names = array_merge($names, array('atro','boss','defend','fast','iguan','maky','poko','tedeo'));
$names = array_merge($names, array('atum','bow','delux','fedel','ilove','mambo','popik','tempo'));
$names = array_merge($names, array('aur','boy','denis','federy','impera','manca','postar','teody'));
$names = array_merge($names, array('ausi','brand','deny','fermi','incomply','mando','price','theta'));
$names = array_merge($names, array('avan','brate','desir','ferra','indu','manga','promete','tibos'));
$names = array_merge($names, array('avia','brit','devel','fiber','ingel','manual','protex','token'));
$names = array_merge($names, array('axe','bro','devil','fifty','inime','marco','pufy','tombo'));
$names = array_merge($names, array('axe','broco','dexter','fili','ioda','marcy','puma','topy'));
$names = array_merge($names, array('axil','bronx','diablo','finy','iomy','margo','pupy','touch'));
$names = array_merge($names, array('aya','bry','diesel','fire','iona','maria','pure','tradex'));
$names = array_merge($names, array('babam','bubu','digger','fisty','iosit','marica','pushk','tranca'));
$names = array_merge($names, array('babau','buca','digi','fizzy','iotor','marko','qanti','trevo'));
$names = array_merge($names, array('babel','bucat','dj','flame','iria','marky','queka','triki'));
$names = array_merge($names, array('baboi','bucon','doare','flavi','iskan','marma','querto','tuga'));
$names = array_merge($names, array('baboo','bucsha','dober','flo','istra','marmo','r2d2','tutan'));
$names = array_merge($names, array('baby','bucsy','doctor','floris','iulio','marock','raby','tuyca'));
$names = array_merge($names, array('bacu','bula','domin','fly','izvine','martin','radik','tyber'));
$names = array_merge($names, array('bad','bulan','domino','flyp','jacks','mascary','radon','tzape'));
$names = array_merge($names, array('badge','bulet','domino','fogy','jaga','master','rafae','tzu'));
$names = array_merge($names, array('badon','buluc','don','fomy','jagor','mateo','rainy','ubix'));
$names = array_merge($names, array('badu','bum','donca','forfa','jamy','mauric','rake','ulie'));
$names = array_merge($names, array('baia','bum','donca','fork','janik','mauser','randy','ultra'));
$names = array_merge($names, array('bala','bunic','doom','fort','japca','mavro','raster','uname'));
$names = array_merge($names, array('balco','burn','dordo','foxy','jeny','maxim','rayn','uragan'));
$names = array_merge($names, array('balo','bust','doris','fredy','jermel','maxima','rebel','vagabo'));
$names = array_merge($names, array('baloo','butoi','dory','free','jespi','medeo','redbu','valcon'));
$names = array_merge($names, array('balti','buton','dot','freezy','joker','mega','redex','valika'));
$names = array_merge($names, array('baly','butter','doto','frost','jolido','mephis','regal','vampi'));
$names = array_merge($names, array('bambina','byzon','draco','fulge','jonest','mercena','renato','vanato'));
$names = array_merge($names, array('bambo','cabak','dracula','futur','jony','metaly','rinoco','varsa'));
$names = array_merge($names, array('bamby','cabom','draga','fuzio','jorga','metro','robo','vasy'));
$names = array_merge($names, array('bandi','caffe','dragon','gabby','juny','micro','roky','veter'));
$names = array_merge($names, array('bane','cali','drake','gabon','just','mielo','rotero','vicio'));
$names = array_merge($names, array('barca','campy','dream','gadar','jyken','mikipo','ruska','victory'));
$names = array_merge($names, array('barlo','cancan','drop','galaxo','kaboom','mirama','sabin','vikin'));
$names = array_merge($names, array('barlona','candy','ducas','gamel','kajil','mircon','sady','vip'));
$names = array_merge($names, array('barsa','cani','duda','garcea','kaju','mision','sakal','viper'));
$names = array_merge($names, array('barsi','canta','dumy','gardo','kaly','mistake','salve','virgi'));
$names = array_merge($names, array('barto','capri','duo','garfeld','kamik','moka','sandy','virux'));
$names = array_merge($names, array('bary','caram','duplex','garlic','kamin','molio','sandy','viva'));
$names = array_merge($names, array('barza','carly','dvdy','garon','zum','molozo','scorpy','warrio'));
	
  if($form_state['values']['usrlevel'] == 1) {
	if ($form_state['values']['usrlevel']>0) {
		for($i=1; $i <= 140; $i++) {
		  $count = 0;
		  do {
			  //random number between 0 and 255
			  $rnd1=ord(drupal_random_bytes(1));
			  $rnd1 = (int) ($rnd1 * 799 / 255);
			  $rnd2=ord(drupal_random_bytes(1));
			  $rnd2 = (int) ($rnd2 * 799 / 255);
			  $rnd3=ord(drupal_random_bytes(1));
			  $rnd3 = (int) ($rnd3 * 999 / 255);
			  
			  $username = $names[$rnd1] . $names[$rnd2] . $rnd3;
			   $sSql  = "SELECT count(*) cnt FROM {users} where name='$username'";
				
				$result = db_query($sSql);
				foreach ($result as $rs) {
					$count = $rs->cnt;
				}
		   }while($count > 1);
		 
		  $new_user = array(
			'name' => $username,
			'pass' => 'Go4' . $username,
			'mail' => $username.'@duel.ro',//'<a href="mailto:user_name@example.com" rel="nofollow">'.$username.'@duel.ro</a>',
			'signature_format' => 'full_html',
			'status' => 1,
			'timezone' => 'America/New_York',
			'init' => $username.'@duel.ro',
			'roles' => array(DRUPAL_AUTHENTICATED_RID => 'authenticated user'),
			'field_first_name' => array(
			'und' => array(
			0 => array(
			'value' => $names[$rnd1],
			),
			),
			),
			'field_last_name' => array(
			  'und' => array(
			    0 => array(
			     'value' => $names[$rnd2],
			    ),
			  ),
			  ),
			);
		  $account= user_save(NULL, $new_user);
		if ($account->uid) {
			// suppose that a source user picture is located in the 'sites/default/files/upics' directory.
			// get image information
			$image_path = "public://pictures/usrpics/b$i.jpg"; 
			$image_path_dest = 'public://pictures/picture-' . $account->uid . '-' . REQUEST_TIME . '.jpg';
			$image_info = image_get_info($image_path);
			  
			// create file object
			$file = new StdClass();
			$file->uid = $account->uid;
			$file->uri = $image_path;
			$file->filemime = $image_info['mime_type'];
			$file->status = 0; // Yes! Set status to 0 in order to save temporary file.
			$file->filesize = $image_info['file_size'];		
			
			// standard Drupal validators for user pictures
			$validators = array(
			  'file_validate_is_image' => array(),
			  'file_validate_image_resolution' => array(variable_get('user_picture_dimensions', '300x3000')),
			  'file_validate_size' => array(variable_get('user_picture_file_size', '30') * 1024),
			);
			
			// here all the magic :)  
			$errors = file_validate($file, $validators);
			if (empty($errors)) {
			  $picture_file = file_copy($file, $image_path_dest);
			  file_usage_add($picture_file, 'user', 'user', $account->uid);
		      db_update('users')
		        ->fields(array(
		        'picture' => $picture_file->fid,
		        ))
		        ->condition('uid', $account->uid)
		        ->execute();
		      $account->picture = $picture_file->fid;
			}
		  }
		}
	}
  }
  else if($form_state['values']['usrlevel'] == 2) {
  	game_war_refresh_positions();
  }
  else if($form_state['values']['usrlevel'] == 3) {
  	game_war_add_users_gamedata();
  	$sSql = "update {user_gamedata} g set g.name = (select u.name from {users} u where u.uid=g.uid)";
  	db_query($sSql);
  }
  else if($form_state['values']['usrlevel'] == 99) {
  	game_war_X0_Data();
  }
  else if($form_state['values']['usrlevel'] == 100) {
  	$sSql = "delete from {user_weapons} where uid= $uid";
	db_query($sSql);
	$sSql = "delete from {user_lupte} where uid= $uid";
	db_query($sSql);
	$sSql = "update {user_gamedata} set strategie=2, soldati=10, soldatiph=1, atacuri=700, atacuriph=3, " .
	  "atacuri_bonus_expire='1000-01-01 00:00:00', atacuri_max=700, atacuri_max_expire='1000-01-01 00:00:00', " .
	  "atac_dublu_last_used='3000-01-01 00:00:00', vot_bon_expire='1000-01-01 00:00:00', vot_stop_expire='1000-01-01 00:00:00', " .
	  "bani=4000, seif=6000, seif_bonus_expire='1000-01-01 00:00:00', card_expire='1000-01-01 00:00:00, medalii_atac=0, " .
	  "medalii_aparare=0, bonus_atac=0, bonus_aparare=0" ;
	db_query($sSql);
	$sSql = "delete from {war_cron}" ;
	db_query($sSql);
	$sSql = "insert into {war_cron} values '2016-11-25 15:00:00', 1, 'reset atacuri_bonus,atacuri_max_bonus, vot_bonusuri, seif_bonus  if expired', 0, 0), " .
       "('2016-11-25 15:00:00', 2, 'reset each hour voturiph, seif_extras', 0, 60), " .
       "('2016-11-21 00:00:00', 3, 'reset duminica noapte seif_depuneri, atac_dublu_last_used', 0, 10080), " .
       "('2016-11-25 00:00:00', 10, 'creste nr. soldati, pozitie in fiecare noapte', 0, 1440), " .
       "('2016-11-25 00:00:00', 20, 'creste banii la 15 min cu nr. soldati * 4(setare); creste atacuri', 0, 15);" ;
	db_query($sSql);
	game_war_refresh_positions();
	game_war_cron_job_1_callback(NULL);
  }
}

/**
 * Form builder for the war game Aliance editing form.
 *
 * @ingroup forms
 * @see game_war_form_alianta_submit()
 * @see game_war_form_alianta_validate()
 */
function game_war_form_alianta($form, &$form_state, $edit = array()) {
	global $user;

	$uid = $user->uid;

	if (!isset($form_state['war_alianta'])) {
		$war_alianta = is_object($edit) ? $edit : (object) $edit;
		$form_state['war_alianta'] = $war_alianta;
	}
	else {
		$war_alianta = $form_state['war_alianta'];
	}

	// @todo Legacy support. Modules are encouraged to access the entity using
	//   $form_state. Remove in Drupal 8.
	$form['#war_alianta'] = $form_state['war_alianta'];

	$form['alianta_tabs'] = array(
			'#type' => 'vertical_tabs',
			'#attached' => array(
					'js' => array(drupal_get_path('module', 'block') . '/block.js'),
			),
	);

	$form['alianta_tabs']['tab_alianta'] = array(
			'#type' => 'fieldset',
			'#title' => t('Alianta'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'alianta_tabs',
			'#weight' => 0,
	);
	$form['alianta_tabs']['tab_alianta']['status_table'] = array(
			'#type' => 'hidden', 
			'#value' => 1, 
			'#prefix' => 'a', 
			'#suffix' => ' x',
	);
	$form['alianta_tabs']['tab_alianta']['submit'] = array(
			'#name' => 'date_update',
			'#type' => 'submit',
			'#value' => t('Update'),
			'#suffix' => "<br>",
	);
	$form['alianta_tabs']['tab_topuri'] = array(
			'#type' => 'fieldset',
			'#title' => t('Topuri'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'alianta_tabs',
			'#weight' => 1,
	);
	$form['alianta_tabs']['tab_topuri']['topuri_table'] = array(
			'#type' => 'hidden',
			'#name' => 'topuri_content',
			'#value' => 1,
			'#prefix' => 'a',
			'#suffix' => ' x',
	);
	$form['alianta_tabs']['tab_loto'] = array(
			'#type' => 'fieldset',
			'#title' => t('Loto'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'alianta_tabs',
			'#weight' => 2,
	);
	$form['alianta_tabs']['tab_loto']['loto_table'] = array(
			'#type' => 'hidden',
			'#name' => 'loto_content',
			'#value' => 1,
			'#prefix' => 'a',
			'#suffix' => ' x',
	);
	$form['alianta_tabs']['tab_loto']['submit'] = array(
			'#name' => 'loto_update',
			'#type' => 'submit',
			'#value' => t('Cumpara'),
			'#suffix' => "<br>",
	);
	
	
	$form['#validate'][] = 'game_war_form_alianta_validate';

	return $form;
}

/**
 * Form validation handler for game_war_form_store().
 *
 * Makes sure that the entered values are valid.
 *
 * @see game_war_form_store()
 * @see game_war_form_store_submit()
 */
function game_war_form_alianta_validate($form, &$form_state) {
	// During the deletion there is no 'machine_name' key
	if (isset($form_state['values']['machine_name'])) {
		// Do not allow machine names to conflict with taxonomy path arguments.
		$machine_name = $form_state['values']['machine_name'];
		$disallowed = array('add', 'list');
		if (in_array($machine_name, $disallowed)) {
			form_set_error('machine_name', t('The machine-readable name cannot be "add" or "list".'));
		}
	}
}

/**
 * Form submission handler for game_war_form_alianta().
 *
 * @see game_war_form_alianta()
 * @see game_war_form_alianta_validate()
 */
function game_war_form_alianta_submit($form, &$form_state) {
	global $user;
	global $game_settings;

	$uid = $user->uid;

	game_war_get_userdata();
	game_war_get_gamesettings();

	if (substr($form_state['triggering_element']['#name'],0,6) == 'cumpar') {
		for($i = 1; $i<$form_state['values']['armacount']; $i++)
		{
			if($form_state['triggering_element']['#name'] == 'cumparma_' . $i)
			{
				$arma = explode('|', $form_state['values']['arma' . $i]);
				if($war_data['bani'] >= $arma[3])
				{
					db_query("update {user_gamedata} set bani=bani-$arma[3] where uid=$uid");
					if(isset($arma[4]))
					{
						db_query("update {user_weapons} set nr=nr+1 where uid=$uid and nid= " . $arma[0]);
					}
					else
					{
						db_query("insert into {user_weapons} values ($uid, $arma[0], $arma[1], $arma[2], 1)");
					}
				}
				else {
					drupal_set_message(t('Fonduri insuficiente'));
				}
			}
		}
		return;
	}
}
/**
 * Form builder for the war game store editing form.
 *
 * @ingroup forms
 * @see game_war_form_store_submit()
 * @see game_war_form_store_validate()
 */
function game_war_form_store($form, &$form_state, $edit = array()) {
  global $user;
    
    $uid = $user->uid;
	// During initial form build, add the entity to the form state for use
	// during form building and processing. During a rebuild, use what is in the
	// form state.
	if (!isset($form_state['war_store'])) {
		$war_store = is_object($edit) ? $edit : (object) $edit;
// 		$defaults = array(
// 				'arme' => 0,
// 				'arme_id' => array(),
// 				'cantit' => array(),
// 				'tip' =>  array(),
// 				'tip' =>  array(),
// 		);
// 		foreach ($defaults as $key => $value) {
// 			if (!isset($war_store->$key)) {
// 				$war_store->$key = $value;
// 			}
// 		}
		$form_state['war_store'] = $war_store;
	}
	else {
		$war_store = $form_state['war_store'];
	}

	// @todo Legacy support. Modules are encouraged to access the entity using
	//   $form_state. Remove in Drupal 8.
	$form['#war_store'] = $form_state['war_store'];

	$form['store_tabs'] = array(
	    '#type' => 'vertical_tabs',
	    '#attached' => array(
	      'js' => array(drupal_get_path('module', 'block') . '/block.js'),
	    ),
	  );
	
	$form['store_tabs']['tab_arme'] = array(
			'#type' => 'fieldset',
			'#title' => t('Arme'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'store_tabs',
			'#weight' => 0,
	);	
	$prefix = '<table class="sticky-table"> <thead> <tr> <th style="width:150px"> ' . t('Arma') . '</th><th> ' . t('Tip') . '</th><th> ' . t('Bonus Puncte') . '</th><th> ' . t('Am deja') . '</th><th> ' . t('Cost') . '</th><th> ' . t('Bucati') . '</th><th> ' . t('Cumpar') . '</th></tr> </thead> <tbody>';
	$sSql  = "SELECT n.title, f1.field_tip_arma_value tip_arma, f2.field_puncte_value puncte, f3.field_pre__value pret, w.nr, n.nid ";
	$sSql .= " FROM {node} n LEFT OUTER JOIN {user_weapons} w ON w.uid=$uid and w.tip=n.nid, {field_data_field_tip_arma} f1 , {field_data_field_puncte} f2 , {field_data_field_pre_} f3 ";
	$sSql .= " WHERE n.type='arma' and n.nid = f1.entity_id and n.nid = f2.entity_id and n.nid = f3.entity_id  ";
	$result = db_query($sSql);
	$arme = 0;
	$style_even = 'even';
	$tiparma = t('Atac');
	foreach ($result as $arm) 
	{
		if($arme % 2 == 1)
			$style_even = 'even';
		else
			$style_even = 'odd';
		if($arm->tip_arma != 0)
			$tiparma = t('Atac');
		else 
			$tiparma = t('Aparare');
		$prefix .= '<tr class="' . $style_even . '"> <td>' . $arm->title . '</td><td>' . $tiparma . '</td><td style="text-align:right;">' . $arm->puncte . '</td><td>' . $arm->nr . '</td><td>' . $arm->pret . '</td><td>';
		$form['store_tabs']['tab_arme']['nrarme' . $arme] = array(
				'#prefix' => $prefix,
				'#name' => 'nrarme_' . $arme,
				'#type' => 'textfield',
				'#maxlength' => 2,
				'#size' => 2,
				'#required' => FALSE,
				'#default_value' => '0',
				'#attributes' => array('onkeydown' => "if (event.keyCode == 13) {  document.getElementById('cumparma_$arme').click(); return false;}"),
		);
		$form['store_tabs']['tab_arme']['arma' . $arme] = array(
				'#type' => 'hidden',
				'#value' => $arm->nid . '|' . $arm->tip_arma . '|' . $arm->puncte. '|' . $arm->pret . '|' . $arm->nr,
				'#name' =>'arma_' . $arme,
				'#id' =>'arma_' . $arme,
		);
		$form['store_tabs']['tab_arme']['cumparma' . $arme] = array(
				'#type' => 'submit',
				'#prefix' => '</td><td>',
				'#name' => 'cumparma_' . $arme,
				'#id' => 'cumparma_' . $arme,
				'#value' => t('Cumpar'),
				'#suffix' => "</td></tr>",
		);
		$prefix = '';
		$arme++;
	}
	$form['store_tabs']['tab_arme']['armacount'] = array(
			'#type' => 'hidden',
			'#value' => $arme,
			'#name' =>'arma_count',
			'#id' =>'arma_count',
			'#suffix' => "</tbody></table>",
	);
	$form['store_tabs']['tab_upgrade'] = array(
			'#type' => 'fieldset',
			'#title' => t('Upgrade'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'store_tabs',
			'#weight' => 1,
	);	
	$form['store_tabs']['tab_upgrade']['arma'] = array(
			'#prefix' => "pref 1 ",
			'#name' => 'cumpara_u1',
			'#type' => 'submit',
			'#value' => t('Cumpara'),
			'#suffix' => "suf 1 <br>",
	);
	$form['store_tabs']['tab_seif'] = array(
			'#type' => 'fieldset',
			'#title' => t('Seif'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'store_tabs',
			'#weight' => 2,
	);	
	$form['store_tabs']['tab_seif']['content'] = array(
			'#prefix' => "pref 1 ",
			'#name' => 'seif_extrage',
			'#type' => 'submit',
			'#value' => t('Extrage'),
			'#suffix' => "suf 1 <br>",
	);
	
	$form['#validate'][] = 'game_war_form_store_validate';

	return $form;
}

/**
 * Form validation handler for game_war_form_store().
 *
 * Makes sure that the entered values are valid.
 *
 * @see game_war_form_store()
 * @see game_war_form_store_submit()
 */
function game_war_form_store_validate($form, &$form_state) {
	// During the deletion there is no 'machine_name' key
	if (isset($form_state['values']['machine_name'])) {
		// Do not allow machine names to conflict with taxonomy path arguments.
		$machine_name = $form_state['values']['machine_name'];
		$disallowed = array('add', 'list');
		if (in_array($machine_name, $disallowed)) {
			form_set_error('machine_name', t('The machine-readable name cannot be "add" or "list".'));
		}
	}
}

/**
 * Form submission handler for game_war_form_store().
 *
 * @see game_war_form_store()
 * @see game_war_form_store_validate()
 */
function game_war_form_store_submit($form, &$form_state) {
  global $user;
  global $game_settings;
  
    $uid = $user->uid; 

    game_war_get_userdata();
    game_war_get_gamesettings();

    if (substr($form_state['triggering_element']['#name'],0,6) == 'cumpar') {
		for($i = 1; $i<$form_state['values']['armacount']; $i++)
		{
			if($form_state['triggering_element']['#name'] == 'cumparma_' . $i)
			{
				$arma = explode('|', $form_state['values']['arma' . $i]);
				if($war_data['bani'] >= $arma[3])
				{
					db_query("update {user_gamedata} set bani=bani-$arma[3] where uid=$uid");
					if(isset($arma[4]))
					{
						db_query("update {user_weapons} set nr=nr+1 where uid=$uid and nid= " . $arma[0]);
					}
					else
					{
						db_query("insert into {user_weapons} values ($uid, $arma[0], $arma[1], $arma[2], 1)");
					}
				}
				else {
					drupal_set_message(t('Fonduri insuficiente'));
				}
			}
		}
		return;
	}
}

function game_war_get_upgrades_table() 
{
	global $user;
	global $war_data;
	global $game_settings;
	
	$sHTML = '<table class="sticky-table"><tbody><tr><td colspan=4 style="text-align: center;">Upgrades</td></tr>';
	$sHTML .= '<tr><td>Tip</td><td>Numar</td><td>Valabil</td><td>Maxim</td></tr>';
	$sHTML .= '<tr><td>Numar mercenari primiti automat la 24 h</td><td>' . $war_data['soldatiph'] . '</td><td>Nelimitat</td><td>' . $game_settings['soldati_max_pe_zi'] . '</td></tr>';
	if($war_data['atacuri_bonus'])
		$sHTML .= '<tr><td>Numar atacuri primite automat la 15 min</td><td>' . $war_data['atacuriph'] . ' din care bonus ' . $war_data['atacuri_bonus'] . 
	              '</td><td>' . date("Y-m-d H:i:s",strtotime($war_data['atacuri_bonus_expire'])) . '</td><td>' . ($game_settings['atacuri']+$game_settings['atacuri_bonusuri']*$game_settings['atacuri_pe_bonus']) . '</td></tr>';
	else
		$sHTML .= '<tr><td>Numar atacuri primite automat la 15 min</td><td>' . $war_data['atacuriph'] . 
	              '</td><td>Nelimitat</td><td>' . ($game_settings['atacuri']+$game_settings['atacuri_bonusuri']*$game_settings['atacuri_pe_bonus']) . '</td></tr>';
	$sHTML .= '</tbody></table>';
	
	return $sHTML;
}
	
/**
 * Form builder for the war game store editing form.
 *
 * @ingroup forms
 * @see game_war_form_status_submit()
 * @see game_war_form_status_validate()
 */
function game_war_form_status($form, &$form_state, $edit = array()) {
global $user;
global $war_data;
global $game_settings;

    game_war_get_gamesettings();
	$uid = $user->uid;
	// During initial form build, add the entity to the form state for use
	// during form building and processing. During a rebuild, use what is in the
	// form state.
	if (!isset($form_state['war_status'])) {
		$war_status = is_object($edit) ? $edit : (object) $edit;
		$form_state['war_status'] = $war_status;
	}
	else {
		$war_status = $form_state['war_status'];
	}

	// @todo Legacy support. Modules are encouraged to access the entity using 
	//   $form_state. Remove in Drupal 8.
	$form['#war_status'] = $form_state['war_status'];

	$form['status_tabs'] = array(
			'#type' => 'vertical_tabs',
			'#attached' => array(
					'js' => array(drupal_get_path('module', 'block') . '/block.js'),
			),
	);

	game_war_get_userdata($user->uid);
    $prefix = '<table class="sticky-table"><tbody><tr><td colspan=3 style="text-align: center;">' . $user->name . '</td></tr>';
    $poza = '<img style="max-width:98px;" src="' . $GLOBALS['base_url'] . '/defimg.jpg">';
    if($user->picture > 0)
    {
    	$account = new StdClass();
    	$account->picture = $user->picture;
    	$account->uid = $user->uid;
    	$account->name = $user->name;
    	$param = array('account' => $account);
    	template_preprocess_user_picture($param);
    	$poza = $param['user_picture'];
    }
    $atac = '';
    for($i = 0; $i<10; $i++) {
    	if(($i+1)*$game_settings['nivel_grad'] < $war_data['bonus_atac'])
    		$atac .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/silver_star_medal.png">';
    	else
    		$atac .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/empty_star_medal.png">';
    }
    $aparare = '';
    for($i = 0; $i<10; $i++) {
    	if(($i+1)*$game_settings['nivel_grad'] < $war_data['bonus_aparare'])
    		$aparare .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/bronze_star_medal.png">';
    	else
    		$aparare .= '<img style="max-width:20px;" title="Multiplu de ' . $game_settings['nivel_grad'] . '" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/empty_star_medal.png">';
    }
    $pericol = intval($war_data['bonus_atac'] / $game_settings['nivel_pericol']) . ' <img style="max-width:30px;" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/star-medal.png" title="0 Atac">' .
    intval($war_data['bonus_aparare'] / $game_settings['nivel_pericol']) . ' <img style="max-width:50px;" src="' . $GLOBALS['base_url'] . '/' . variable_get('file_public_path', 'sites/duel.dinviselemele.ro/files') . '/img/star_sheriff.png" title="0 Aparare">';
    $prefix .= '<tr><td rowspan=7>' . $poza . '</td><td>' . 'Cazarma:' . '</td><td><b>' . $war_data['soldati'] . '</b> ' . t('Soldati') . ' (' . $war_data['soldatiph'] . ' pe zi)</td></tr>';
    $prefix .= '<tr><td>' . 'Buget:' . '</td><td><b title=" 4 * soldati la 15 min">' . $war_data['bani'] . '</b> ' . $game_settings['moneda'] . '<br> seif:' . $war_data['seif'] . ' ' . $game_settings['moneda'] . '<br> total:' . ($war_data['bani']+$war_data['seif']) . ' ' . $game_settings['moneda'] . '</td></tr>';
    $prefix .= '<tr><td>' . 'Bonus:' . '</td><td>' . $war_data['bonus_atac'] . ' - ' . $war_data['bonus_aparare'] . '</td></tr>';
    $prefix .= '<tr><td>' . 'Atacuri:' . '</td><td>' . $war_data['atacuri'] . ' / ' . $war_data['bonus_aparare'] . '</td></tr>';
    $prefix .= '<tr><td>' . 'Atac:' . '</td><td>' . $atac . '</td></tr>';
    $prefix .= '<tr><td>' . 'Aparare:' . '</td><td>' . $aparare . '</td></tr>';
    $prefix .= '<tr><td>' . 'Pericol:' . '</td><td>' . $pericol . '</td></tr>';
    $suffix = '</tbody></table>' . game_war_get_upgrades_table();
    //<img typeof="foaf:Image" src="http://localhost/d7/sites/duel.dinviselemele.ro/files/styles/thumbnail/public/pictures/picture-17-1479227257.jpg?itok=hSrMPwLH" alt="imaginea utilizatorului babau" title="imaginea utilizatorului babau" />
// 	$sSql  = "SELECT n.title, f1.field_tip_arma_value tip_arma, f2.field_puncte_value puncte, f3.field_pre__value pret, w.nr, n.nid ";
// 	$sSql .= " FROM {node} n LEFT OUTER JOIN {user_weapons} w ON w.uid=$uid and w.tip=n.nid, {field_data_field_tip_arma} f1 , {field_data_field_puncte} f2 , {field_data_field_pre_} f3 ";
// 	$sSql .= " WHERE n.type='arma' and n.nid = f1.entity_id and n.nid = f2.entity_id and n.nid = f3.entity_id  ";
// 	$result = db_query($sSql);
	$style=0;
	$form['status_tabs']['tab_status'] = array(
			'#type' => 'fieldset',
			'#title' => t('Stare'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'status_tabs',
			'#weight' => 0,
	);
	{
		
		$form['status_tabs']['tab_status']['status_table'] = array(
				'#type' => 'hidden',  
				'#value' => 1, 
				'#prefix' => $prefix, 
				'#suffix' => $suffix,
		);
	
	}
	$form['status_tabs']['tab_date'] = array(
			'#type' => 'fieldset',
			'#title' => t('Date Personale'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'status_tabs',
			'#weight' => 1,
	);
	$strateg = array(0 => t('Ofensiv'), 1 => t('Defensiv'), 2 => t('Echilibrat'));
	$form['status_tabs']['tab_date']['table_date'] = array(
			'#title' => t('Strategie'),
			'#type' => 'radios', 
			'#default_value' => 2,
			'#options' => $strateg,
			'#required' => TRUE,
			'#description' => t('Se poate schimba la 30 zile.'),
	);
	$form['status_tabs']['tab_date']['submit'] = array(
			'#name' => 'date_update',
			'#type' => 'submit',
			'#value' => t('Update'),
			'#suffix' => "<br>",
	);
	$form['status_tabs']['tab_atacuri'] = array(
			'#type' => 'fieldset',
			'#title' => t('Atacuri'),
			'#collapsible' => TRUE,
			'#collapsed' => TRUE,
			'#group' => 'status_tabs',
			'#weight' => 2,
	);
	$form['status_tabs']['tab_atacuri']['table_atacuri'] = array(
			'#type' => 'hidden', 
			'#value' => 1, 
			'#prefix' => 'a', 
			'#suffix' => ' ',
	);
	

	$form['#validate'][] = 'game_war_form_status_validate';

	return $form;
}

/**
 * Form validation handler for game_war_form_status().
 *
 * Makes sure that the entered values are valid.
 *
 * @see game_war_form_status()
 * @see game_war_form_status_submit()
 */
function game_war_form_status_validate($form, &$form_state) {
	// During the deletion there is no 'machine_name' key
	if (isset($form_state['values']['machine_name'])) {
		// Do not allow machine names to conflict with taxonomy path arguments.
		$machine_name = $form_state['values']['machine_name'];
		$disallowed = array('add', 'list');
		if (in_array($machine_name, $disallowed)) {
			form_set_error('machine_name', t('The machine-readable name cannot be "add" or "list".'));
		}
	}
}

/**
 * Form submission handler for game_war_form_status().
 *
 * @see game_war_form_status()
 * @see game_war_form_status_validate()
 */
function game_war_form_status_submit($form, &$form_state) {
	global $user;
	global $game_settings;

	$uid = $user->uid;

	game_war_get_userdata();
	game_war_get_gamesettings();

	if (substr($form_state['triggering_element']['#name'],0,6) == 'cumpar') {
		for($i = 1; $i<$form_state['values']['armacount']; $i++)
		{
			if($form_state['triggering_element']['#name'] == 'cumparma_' . $i)
			{
				$arma = explode('|', $form_state['values']['arma' . $i]);
				if($user->war_data['bani'] >= $arma[3])
				{
					db_query("update {user_gamedata} set bani=bani-$arma[3] where uid=$uid");
					if(isset($arma[4]))
					{
						db_query("update {user_weapons} set nr=nr+1 where uid=$uid and nid= " . $arma[0]);
					}
					else
					{
						db_query("insert into {user_weapons} values ($uid, $arma[0], $arma[1], $arma[2], 1)");
					}
				}
				else {
					drupal_set_message(t('Fonduri insuficiente'));
				}
			}
		}
		return;
	}
}
