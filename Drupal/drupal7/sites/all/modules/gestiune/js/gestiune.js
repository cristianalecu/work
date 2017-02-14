
var max_id_intrari = 0;
var nr_intrari = 1;
var idCRTs = [];       // new Array();  //crt pos for every entry
 
idCRTs[0] = 1;
var supplier;

function get_items_combo(i, itm_ndx)
{
	var sHTML = '';
	var itnm = '';
	var itopts = '';
	
		supplier = 0;
		var objDomEntry = document.getElementById('edit-field-supplier-und');
		if(objDomEntry != null)
		{
			if(objDomEntry.value != '_none')
			  for(ndxItem = 0; ndxItem < objDomEntry.length; ndxItem++) 
				  {
				     if(objDomEntry.value == objDomEntry[ndxItem].value)
				     {
				    	 supplier = objDomEntry.value;
				    	 break;
				     }
				  }
		}
		sHTML += '<select id="item_name_combo_' + i + '" name="item_name_combo_' + i + '" class="form-select" onchange="change_itm(' + i + ')">';
		for(ndxItem = 0; ndxItem < it_names.length; ndxItem++)
		{
			if(itm_ndx < 0 )
			{
				itnm = '<option selected value="-1"> </option>';
			}
			else if(itm_ndx == ndxItem)
			{
				itnm = '<option selected value="' + ndxItem + '">' + it_names[ndxItem] + '</option>';
			}
			if(supplier == 0 || (supplier > 0 && supplier == it_suppls[ndxItem]) )
			{
				itopts += '<option value="' + ndxItem + '">' + it_names[ndxItem] + '</option>';
			}
		}
		sHTML += itnm + itopts + '</select>';
		//itnm=it_names[itm_ndx];

	sHTML += '<input type="hidden" id="itm_ndx_' + i + '" name="itm_ndx_' + i + '" value="' + itm_ndx + '">';
	return sHTML;
}

function supplier_change()
{
	calc_subtot();
}

function change_itm(i) 
{
	var ndxItem;
	var objDomEntry;
	
	var itm_entry = document.getElementById('item_name_combo_' + i).value;

	if(itm_entry > 0)
	{
		objDomEntry = document.getElementById('item_code_text_' + i);
		objDomEntry.value = it_codes[itm_entry];
		objDomEntry = document.getElementById('item_barcode_text_' + i);
		objDomEntry.value = it_barcodes[itm_entry];
		objDomEntry = document.getElementById('unitm_' + i);
		objDomEntry.innerHTML = it_ums[itm_entry];
		objDomEntry = document.getElementById('unitp_' + i);
		objDomEntry.innerHTML = it_prices[itm_entry];
		adjust_qty(i);
		objDomEntry = document.getElementById('quantity_text_' + i);
		objDomEntry.focus();
		objDomEntry.setSelectionRange(0, objDomEntry.value.length);
	}
	else
	{
		objDomEntry = document.getElementById('item_code_text_' + i);
		objDomEntry.value = "";
		objDomEntry = document.getElementById('item_barcode_text_' + i);
		objDomEntry.value = "";
		objDomEntry = document.getElementById('unitm_' + i);
		objDomEntry.innerHTML = "";
		objDomEntry = document.getElementById('unitp_' + i);
		objDomEntry.innerHTML = "";
		objDomEntry = document.getElementById('val_nvat_' + i);
		objDomEntry.innerHTML = '<input type="hidden" id="itm_val_' + i + '" name="itm_val_' + i + '" value="0">';
		objDomEntry = document.getElementById('item_barcode_text_' + i);
		objDomEntry.focus();
	}
}

function search_item_by_code(i) {
	var ndxItem;
	var objDomEntry;
	
	var itm_entry = document.getElementById('item_code_text_' + i).value;
	
	if(itm_entry.length == 0)
		return;
	
	for(ndxItem = 0; ndxItem < it_names.length; ndxItem++) 
	{
		if(itm_entry.localeCompare(it_codes[ndxItem]) == 0 || 
		    (it_codes2[ndxItem].length > 0 && itm_entry.localeCompare(it_codes2[ndxItem]) == 0)   )
		{
			break;
		}
	}
	if(ndxItem < it_names.length)
	{
		objDomEntry = document.getElementById('item_name_' + i);
		objDomEntry.innerHTML = get_items_combo(i,ndxItem);
		objDomEntry = document.getElementById('item_barcode_text_' + i);
		objDomEntry.value = it_barcodes[ndxItem];
		objDomEntry = document.getElementById('unitm_' + i);
		objDomEntry.innerHTML = it_ums[ndxItem];
		objDomEntry = document.getElementById('unitp_' + i);
		objDomEntry.innerHTML = it_prices[ndxItem];
		adjust_qty(i);
		objDomEntry = document.getElementById('quantity_text_' + i);
		ndxItem = parseInt(objDomEntry.value);
		objDomEntry.focus();
		objDomEntry.setSelectionRange(0, objDomEntry.value.length);
	}
	else
	{
		objDomEntry = document.getElementById('item_name_' + i);
		objDomEntry.innerHTML = get_items_combo(i, -1);
		objDomEntry = document.getElementById('item_barcode_text_' + i);
		objDomEntry.value = "";
		objDomEntry = document.getElementById('unitm_' + i);
		objDomEntry.innerHTML = "";
		objDomEntry = document.getElementById('unitp_' + i);
		objDomEntry.innerHTML = "";
		objDomEntry = document.getElementById('val_nvat_' + i);
		objDomEntry.innerHTML = '<input type="hidden" id="itm_val_' + i + '" name="itm_val_' + i + '" value="0">';
		objDomEntry = document.getElementById('item_code_text_' + i);
		objDomEntry.value = "";
		window.alert("Acest Item Code nu a fost gasit.")
		objDomEntry.focus();
	}
}

function search_item_by_barcode(i) {
	var ndxItem;
	var objDomEntry;
	
	var itm_entry = document.getElementById('item_barcode_text_' + i).value;
	
	if(itm_entry.length == 0)
		return;
	
	for(ndxItem = 0; ndxItem < it_names.length; ndxItem++) 
	{
		if(it_barcodes[ndxItem].length > 0 && itm_entry.localeCompare(it_barcodes[ndxItem]) == 0)
		{
			break;
		}
	}

	if(ndxItem < it_names.length)
	{
		objDomEntry = document.getElementById('item_name_' + i);
		objDomEntry.innerHTML = get_items_combo(i, ndxItem);
		objDomEntry = document.getElementById('item_code_text_' + i);
		objDomEntry.value = it_codes[ndxItem];
		objDomEntry = document.getElementById('unitm_' + i);
		objDomEntry.innerHTML = it_ums[ndxItem];
		objDomEntry = document.getElementById('unitp_' + i);
		objDomEntry.innerHTML = it_prices[ndxItem];
		adjust_qty(i);
		objDomEntry = document.getElementById('quantity_text_' + i);
		ndxItem = parseInt(objDomEntry.value);
		objDomEntry.focus();
		objDomEntry.setSelectionRange(0, objDomEntry.value.length);
	}
	else
	{
		objDomEntry = document.getElementById('item_name_' + i);
		objDomEntry.innerHTML = get_items_combo(i, -1);
		objDomEntry = document.getElementById('item_code_text_' + i);
		objDomEntry.value = "";
		objDomEntry = document.getElementById('unitm_' + i);
		objDomEntry.innerHTML = "";
		objDomEntry = document.getElementById('unitp_' + i);
		objDomEntry.innerHTML = "";
		objDomEntry = document.getElementById('val_nvat_' + i);
		objDomEntry.innerHTML = '<input type="hidden" id="itm_val_' + i + '" name="itm_val_' + i + '" value="0">';
		objDomEntry = document.getElementById('item_barcode_text_' + i);
		objDomEntry.value = "";
		window.alert("Acest barcode nu a fost gasit.")
		objDomEntry.focus();
	}
}

function adjust_qty(i) {
	var objDomEntry;
	var strHtml;
	var ndxItm;
    var sQty = 0;
    var sTotal = 0;
	
	objDomEntry = document.getElementById('quantity_text_' + i);
	var qty = parseInt(objDomEntry.value);
	if(isNaN(qty))
	{
		qty = 0;
		objDomEntry.value = "0";
	}
	objDomEntry = document.getElementById('unitp_' + i);
	var prc = parseFloat(objDomEntry.innerHTML);
	if(isNaN(prc))
	{
		prc = 0;
	}
	prc *= qty;
	objDomEntry = document.getElementById('val_nvat_' + i);
	objDomEntry.innerHTML = "" + prc + '<input type="hidden" id="itm_val_' + i + '" name="itm_val_' + i + '" value="' + prc + '">';
	
	objDomEntry = document.getElementById('item_name_combo_' + i);
	ndxItm = objDomEntry.value;
	objDomEntry = document.getElementById('item_name_' + i);
	objDomEntry.innerHTML = get_items_combo(i, ndxItm);

	for(ndxEntry = 0; ndxEntry <= max_id_intrari; ndxEntry++) 
	{
		objDomEntry = document.getElementById('quantity_text_' + ndxEntry);
		if(objDomEntry != null)
		{
			qty = parseInt(objDomEntry.value); 
			if(!isNaN(qty))
				sQty += qty;
		}
		objDomEntry = document.getElementById('itm_val_' + ndxEntry);
		if(objDomEntry != null)
		{
			prc = parseInt(objDomEntry.value); 
			if(!isNaN(prc))
				sTotal += prc;
		}
	}
	objDomEntry = document.getElementById('total_suma');
	objDomEntry.innerHTML = 'Total cantitate: ' + sQty + '  Suma: ' + sTotal ;
}

function add_entry(i) {
	var ndxEntry;
	var objDomEntry;
	var strHtml;
	
	var pos_entry = parseInt(document.getElementById('pos_entry_' + i).value);
    for(ndxEntry = 0; ndxEntry <= max_id_intrari; ndxEntry++) {
    	if(idCRTs[ndxEntry] > pos_entry) {
    		idCRTs[ndxEntry] = idCRTs[ndxEntry] + 1;
    		objDomEntry=document.getElementById('nr_crt_' + ndxEntry);
    		strHtml = '<td id="nr_crt_' + ndxEntry + '">' + idCRTs[ndxEntry] + '<input type="hidden" id="pos_entry_' + ndxEntry + '" name="pos_enptry_' + ndxEntry + '" value="' + idCRTs[ndxEntry] + '"></td>';
    		objDomEntry.outerHTML = strHtml;
    	}
	}

    max_id_intrari++;
    idCRTs[max_id_intrari] = pos_entry + 1;
	objDomEntry = document.getElementById('tab_entry_' + i);
	strHtml = '<tr id="tab_entry_' + max_id_intrari + '">';
	strHtml=strHtml+'  <td id="nr_crt_' + max_id_intrari + '">' + idCRTs[max_id_intrari] + '<input type="hidden" id="pos_entry_' + max_id_intrari + '" name="pos_enptry_' + max_id_intrari + '" value="' + idCRTs[max_id_intrari] + '"></td>';
	strHtml=strHtml+'  <td id="item_name_' + max_id_intrari + '">' + get_items_combo(max_id_intrari, -1) + '</td>';
	strHtml=strHtml+'  <td id="item_code_' + max_id_intrari + '"><input onblur="search_item_by_code(' + max_id_intrari + ');" onkeydown="if (event.keyCode == 13) {search_item_by_code(' + max_id_intrari + '); return false;}" type="text" id="item_code_text_' + max_id_intrari + '" name="item_code_text_' + max_id_intrari + '" value="" size="15" maxlength="15" class="form-text"></td>';
	strHtml=strHtml+'  <td id="item_barcode_' + max_id_intrari + '"><input onblur="search_item_by_barcode(' + max_id_intrari + ');" onkeydown="if (event.keyCode == 13) {search_item_by_barcode(' + max_id_intrari + '); return false;}" type="text" id="item_barcode_text_' + max_id_intrari + '" name="item_barcode_text_' + max_id_intrari + '" value="" size="15" maxlength="15" class="form-text"></td>';
	strHtml=strHtml+'  <td id="quantity_' + max_id_intrari + '"><input onblur="adjust_qty(' + max_id_intrari + ');" onkeydown="if (event.keyCode == 13) {adjust_qty(' + max_id_intrari + ');add_entry(' + max_id_intrari + '); return false;}" type="text" id="quantity_text_' + max_id_intrari + '" name="quantity_text_' + max_id_intrari + '" value="" size="5" maxlength="5" class="form-text"></td>';
	strHtml=strHtml+'  <td id="unitm_' + max_id_intrari + '"> </td>';
	strHtml=strHtml+'  <td id="unitp_' + max_id_intrari + '"> </td>';
	strHtml=strHtml+'  <td id="val_nvat_' + max_id_intrari + '"> <input type="hidden" id="itm_val_' + max_id_intrari + '" name="itm_val_' + max_id_intrari + '" value="0"></td>';
	strHtml=strHtml+'  <td><input type="submit" id="cmdAdd_' + max_id_intrari + '" name="cmdAdd_' + max_id_intrari + '" value="+" class="form-submit" onclick="add_entry(' + max_id_intrari + ');return false;"><input type="submit" id="cmdDel_' + max_id_intrari + '" name="cmdDel_' + max_id_intrari + '" value="-" class="form-submit" onclick="del_entry(' + max_id_intrari + ');return false;"></td>';
	strHtml=strHtml+' </tr>';
	//objDomEntry.outerHTML = objDomEntry.outerHTML + strHtml;
	objDomEntry.insertAdjacentHTML('afterend', strHtml);
	
	nr_intrari++;
	
	objDomEntry = document.getElementById('max_id_intrari');
	objDomEntry.value = "" + max_id_intrari;
	
	objDomEntry = document.getElementById('item_code_text_' + max_id_intrari);
	objDomEntry.focus();
}

function calc_subtot() {
	var ndxEntry;
	for(ndxEntry = 0; ndxEntry <= max_id_intrari; ndxEntry++) 
	{
		if(idCRTs[ndxEntry] > 0) 
		{
			adjust_qty(ndxEntry);
		}
	}
}

function del_entry(i) {
	var ndxEntry;
	var objDomEntry;
	var strHtml;
	
	if(nr_intrari == 1)
		return;
	
	var pos_entry = parseInt(document.getElementById('pos_entry_' + i).value);
    for(ndxEntry = 0; ndxEntry <= max_id_intrari; ndxEntry++) 
    {
    	if(idCRTs[ndxEntry] > pos_entry) 
    	{
    		idCRTs[ndxEntry] = idCRTs[ndxEntry] - 1;
    		objDomEntry=document.getElementById('nr_crt_' + ndxEntry);
    		strHtml = '<td id="nr_crt_' + ndxEntry + '">' + idCRTs[ndxEntry] + '<input type="hidden" id="pos_entry_' + ndxEntry + '" name="pos_enptry_' + ndxEntry + '" value="' + idCRTs[ndxEntry] + '"></td>';
    		objDomEntry.outerHTML = strHtml;
    	}
	}

    idCRTs[i] = 0;   // no position - deleted
	objDomEntry = document.getElementById('tab_entry_' + i);
	objDomEntry.outerHTML = " ";
	nr_intrari--;
	
}

jQuery().ready(function() 
{
    var strHtml;
    var sQty = 0;
    var sTotal = 0;
    
    var objDomEntry = document.getElementById('edit-field-supplier-und');
    if(objDomEntry != null)
    {
	    objDomEntry.addEventListener(
	    	     'change',
	    	     function() {supplier_change();},
	    	     false
	    	  );   	
    }
    var myDiv = document.getElementById('edit-field-article-attach');
    myDiv.outerHTML =  '<div id="intrariraport"> </div>' + myDiv.outerHTML;
    myDiv = document.getElementById('intrariraport');
    var strDiv = '<div id="edit-field-intrari-raport">';
    strDiv=strDiv+'<fieldset id="edit-field-intrari-raport-und" class="form-wrapper">';
    strDiv=strDiv+'<legend><span class="fieldset-legend">Intrari</span></legend>';
    if(tab_ndx.length == 0)
    	strDiv=strDiv+'<input type="hidden" id="max_id_intrari" name="max_id_intrari" value="0">';
    else
    	strDiv=strDiv+'<input type="hidden" id="max_id_intrari" name="max_id_intrari" value="' + (tab_ndx.length-1) + '">';
    strDiv=strDiv+' <table class="views-table"><thead><tr>';
    strDiv=strDiv+'  <th>No Crt</th><th>Item Name</th><th>Item Code</th><th>Barcode</th><th>Qty</th>';
    strDiv=strDiv+'  <th>UM</th><th>Unit Price</th><th>Value w/o VAT</th><th> </th>';
    strDiv=strDiv+' </tr></thead><tbody>';
    if(tab_ndx.length == 0)
    {
	    strDiv=strDiv+' <tr id="tab_entry_0"> <td id="nr_crt_0">1<input type="hidden" id="pos_entry_0" name="pos_enptry_0" value="1"></td>';
	    strDiv=strDiv+'  <td id="item_name_0">' + get_items_combo(0, -1) + '</td>';
	    strDiv=strDiv+'  <td id="item_code_0"><input onblur="search_item_by_code(0);"  onkeydown="if (event.keyCode == 13) {search_item_by_code(0); return false;}" type="text" id="item_code_text_0" name="item_code_text_0" value="" size="15" maxlength="15" class="form-text"></td>';
	    strDiv=strDiv+'  <td id="item_barcode_0"><input onblur="search_item_by_barcode(0);" onkeydown="if (event.keyCode == 13) {search_item_by_barcode(0); return false;}" type="text" id="item_barcode_text_0" name="item_barcode_text_0" value="" size="15" maxlength="15" class="form-text"></td>';
	    strDiv=strDiv+'  <td id="quantity_0"><input onblur="adjust_qty(0);"  onkeydown="if (event.keyCode == 13) {adjust_qty(0); add_entry(0);return false;}" type="text" id="quantity_text_0" name="quantity_text_0" value="" size="5" maxlength="5" class="form-text"></td>';
	    strDiv=strDiv+'  <td id="unitm_0"> </td>';
	    strDiv=strDiv+'  <td id="unitp_0"> </td>';
	    strDiv=strDiv+'  <td id="val_nvat_0"> <input type="hidden" id="itm_val_0" name="itm_val_0" value="0"></td>';
	    strDiv=strDiv+'  <td><input type="submit" id="cmdAdd_0" name="cmdAdd_0" value="+" class="form-submit" onclick="add_entry(0);return false;"><input type="submit" id="cmdDel_0" name="cmdDel_0" value="-" class="form-submit" onclick="del_entry(0);return false;"></td>';
	    strDiv=strDiv+' </tr>';
    }
    else
	{
    	nr_intrari = tab_ndx.length;
    	max_id_intrari = nr_intrari - 1;
    	for(var i=0; i<nr_intrari; i++)
    	{
    		idCRTs[i] = i+1
    		strHtml = '<tr id="tab_entry_' + i + '">';
    		strHtml=strHtml+'  <td id="nr_crt_' + i + '">' + idCRTs[i] + '<input type="hidden" id="pos_entry_' + i + '" name="pos_enptry_' + i + '" value="' + idCRTs[i] + '"></td>';
    		strHtml=strHtml+'  <td id="item_name_' + i + '">' + get_items_combo(i, tab_ndx[i]) + '</td>';
    		strHtml=strHtml+'  <td id="item_code_' + i + '"><input onblur="search_item_by_code(' + i + ');" onkeydown="if (event.keyCode == 13) {search_item_by_code(' + i + '); return false;}" type="text" id="item_code_text_' + i + '" name="item_code_text_' + i + '" value="' + it_codes[tab_ndx[i]] + '" size="15" maxlength="15" class="form-text"></td>';
    		strHtml=strHtml+'  <td id="item_barcode_' + i + '"><input onblur="search_item_by_barcode(' + i + ');" onkeydown="if (event.keyCode == 13) {search_item_by_barcode(' + i + '); return false;}" type="text" id="item_barcode_text_' + i + '" name="item_barcode_text_' + i + '" value="' + it_barcodes[tab_ndx[i]] + '" size="15" maxlength="15" class="form-text"></td>';
    		strHtml=strHtml+'  <td id="quantity_' + i + '"><input onblur="adjust_qty(' + i + ');" onkeydown="if (event.keyCode == 13) {adjust_qty(' + i + ');add_entry(' + i + '); return false;}" type="text" id="quantity_text_' + i + '" name="quantity_text_' + i + '" value="' + tab_qty[i] + '" size="5" maxlength="5" class="form-text"></td>';
    		strHtml=strHtml+'  <td id="unitm_' + i + '">' + it_ums[tab_ndx[i]] + '</td>';
    		strHtml=strHtml+'  <td id="unitp_' + i + '">' + it_prices[tab_ndx[i]] + '</td>';
    		strHtml=strHtml+'  <td id="val_nvat_' + i + '">' + tab_val[i] + '<input type="hidden" id="itm_val_' + i + '" name="itm_val_' + i + '" value="' + tab_val[i] + '"></td>';
    		strHtml=strHtml+'  <td><input type="submit" id="cmdAdd_' + i + '" name="cmdAdd_' + i + '" value="+" class="form-submit" onclick="add_entry(' + i + ');return false;"><input type="submit" id="cmdDel_' + i + '" name="cmdDel_' + i + '" value="-" class="form-submit" onclick="del_entry(' + i + ');return false;"></td>';
    		strHtml=strHtml+' </tr>';
    		strDiv=strDiv+strHtml;
    		sQty += tab_qty[i];
    		sTotal += tab_val[i];
    	}
	}
    strDiv=strDiv+'</tbody></table> ';
    strDiv=strDiv+'<div id="total_suma" style="text-align: right;"> Total cantitate: ' + sQty + '  Suma: ' + sTotal + '</div>';
    strDiv=strDiv+'</fieldset></div>';
    
    myDiv.innerHTML = strDiv;

    myDiv = document.getElementById('item_code_text_0');
    myDiv.focus();
});  

//<select id="item_name_combo" name="item_name_combo" class="form-select"></select>
//<option value="240">TIG. GLAMOUR SUNSHINE BLS 10</option>