<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Sistema</title>
<link href="css/vmc.css" rel="stylesheet" type="text/css"></link>
<script type="text/javascript" charset="utf-8" src="js/jquery.min.js"></script>
<script language="javascript" src="js/vignTables.js"></script>
<script language="javascript" src="js/common.js"></script>

{literal}
<script language="javascript">
function msgAlerta(msg){
		if(msg!=''&&msg!=null){
			alert(msg);
		} 
}
</script>
{/literal}

</head>
<body leftmargin="0" marginwidth="0" topmargin="0" marginheight="0" class="vign-consoleBody" onload="msgAlerta('{$msgAlert}');">
	<table id="table_master_table" width="100%" height="100%" cellpadding="0" cellspacing="0" border="0" class="vign-headerBackground">
		<tr class="vign-headerBackground2">
			<td class="vign-headerLogo" height="30" width="150"><img src="img/dotclear.gif" alt="" height="30" width="150" border="0"></td>
			<td class="vign-rightside-header" width="90%" colspan="2"><img src="img/dotclear.gif" alt="" height="30" width="600" border="0"></td>
        	</tr>
        	<tr class="vign-navbar" style="display:none">
                	<td id="vign-headerTitle" height="23">&nbsp;</td>
                	<td class="vign-rightside" colspan="2" id="vign-navcontainer">&nbsp;</td>
	        </tr>
        	<tr>
		        <td height="22" valign="top" colspan="3" id="vign-menucontainer">
	
	<script language="javascript" src="js/vignMenu.js"></script>

				<ul>

			                <li id="menuM0" onMouseOver="consoleMenus[0].showMenu()" onMouseOut="consoleMenus[0].hideMenu()"><a href="index.php?op=servidor" id="servidor">Servidor</a></li>
			                <li id="menuM1" onMouseOver="consoleMenus[1].showMenu()" onMouseOut="consoleMenus[1].hideMenu()"><a href="index.php?op=servico" id="servico">Servi�o</a></li>
			                <li id="menuM2" onMouseOver="consoleMenus[2].showMenu()" onMouseOut="consoleMenus[2].hideMenu()"><a href="index.php?op=usuario" id="usuario">Usu�rio</a></li>
			                <li id="menuM3" onMouseOver="consoleMenus[3].showMenu()" onMouseOut="consoleMenus[3].hideMenu()"><a href="index.php?op=empresa" id="empresa">Empresa</a></li>
			                <li class="last_item">&nbsp;</li>
			        </ul>
	<script language="javascript" src="js/vignMenuConfig.js"></script>


			</td>
		</tr>

		<tr>
			<td height="7" colspan="3"><img  src="img/dotclear.gif"   height="7" width="1" alt=""></td>
		</tr>
