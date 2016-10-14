
$('#new').click(function() {
	var ret = prompt("New 'to do element'");
	ret = ret.trim();
	if (ret.length > 0)
	{
		$('#ft_list').prepend("<div onclick=deleteToDo(this)>" + ret + "</div>");
		setCookie('todolist', $('#ft_list').html(), 1);
	}
})

function deleteToDo(id) {
	if (confirm('Want to delete this ?')) {
		$(id).remove();
		setCookie('todolist', $('#ft_list').html(), 1);
	}
}

function setCookie(cname, cvalue, exdays) {
	var d = new Date();
	d.setTime(d.getTime() + (exdays*24*60*60*1000));
	var expires = "expires="+ d.toUTCString();
	document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie(cname) {
	var name = cname + "=";
	var ca = document.cookie.split(';');
	for(var i = 0; i <ca.length; i++) {
		var c = ca[i];
		while (c.charAt(0)==' ') {
			c = c.substring(1);
		}
		if (c.indexOf(name) == 0) {
			return c.substring(name.length,c.length);
		}
	}
	return "";
}

function refresh() {
	$('#ft_list').html(getCookie('todolist'));
}
