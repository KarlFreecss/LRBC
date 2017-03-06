<html>
<head>
<meta charset="utf-8"/>
</head>
<title>test</title>
<body>
<table border="1" cellspacing="0" cellpadding="0">

<?php
$par=substr($_SERVER["QUERY_STRING"], 5);

$mysql_server_name="localhost";
$mysql_username="root";
$mysql_password="";
$mysql_database="ACM_contests";

if (strlen($par) > 2)
	exit;

$conn=mysql_connect($mysql_server_name,$mysql_username,$mysql_password);

mysql_query("set names 'utf9'");
mysql_select_db($mysql_database);
$sql ="select * from contest_record where c_id = ". "\"$par\"";
$result = mysql_query($sql,$conn);


while($row = mysql_fetch_array($result)) {
	#echo "<div style=\"height:24px; line-height:24px; font-weight:bold;\">";
	echo "<tr>";
	echo "<td colspan=\"1\" class=\"item\">" . $row['p_id'] . "</td>";
	echo "<td colspan=\"1\" class=\"item\">" . $row['p_time'] . "</td>"; 	
	echo "<td colspan=\"1\" class=\"item\">" . $row['result'] . "</td>";
	#echo "<td colspan=\"1\" class=\"item\">" . $row['err_reason'] . "</td>";
	#echo "<a href=\"contest.php?c_id=" . $row['c_id'] . "\">" . $row['c_name'] . "</a>    (" . $row[c_time] . ")<br/>";
	echo "</tr>";
}

function convertUrlQuery($query)
{
  $queryParts = explode('&', $query);
  $params = array();
  foreach ($queryParts as $param) {
    $item = explode('=', $param);
    $params[$item[0]] = $item[1];
  }
  return $params;
}
?>

</table>
</body>
</html>

