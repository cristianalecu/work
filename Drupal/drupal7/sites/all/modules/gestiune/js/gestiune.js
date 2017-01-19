
var current_object = 0;
var current_id = 0;
var ids = [];       // new Array();

jQuery().ready(function() {
    
jQuery('.notaTooltip').each(function() { 
    jQuery(this).qtip({
        content: {
            text: jQuery(this).next('div') // Use the "div" element next to this for the content
        },
        hide: {
            event: 'unfocus'  
        }
    });
});


jQuery('.trimTooltip').each(function() { 
	if(this.attributes[1].nodeValue == "#") 
	{
		current_object = this;
		current_id = this.attributes[0].nodeValue;
		ids[ids.length] = "6_2_" + current_id;
	}
	else 
    jQuery(this).qtip({
        content: {
            text: jQuery(this).next('div') // Use the "div" element next to this for the content
        },
        hide: {
            delay: 500
        }
    });
});

if(ids.length > 0)
	{
	jQuery.getJSON(window.location.origin + "/get_verset/" + ids.join("/"), function(json) {
		
		jQuery.each(json, function( index, value ) {
		  var c_obj = document.getElementById(value[4]);
		  c_obj.href = value[2];
		  if(c_obj.innerHTML.trim() == "")
			c_obj.innerHTML = value[3];
		  jQuery(c_obj).qtip({
			content: {
			text: value[1]
			},
			hide: {
			delay: 500
			}
			}); 
        });
	});
	
	}

  });  