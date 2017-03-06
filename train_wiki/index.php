<html>
<title>test</title>
<body>
<?php

$mysql_server_name="localhost";
$mysql_username="root";
$mysql_password="";
$mysql_database="ACM_contests";

$conn=mysql_connect($mysql_server_name,$mysql_username,$mysql_password);

mysql_query("set names 'utf8'");
mysql_select_db($mysql_database);
$sql ="select * from contests";
$result = mysql_query($sql,$conn);

while($row = mysql_fetch_array($result)) {
	echo "<div style=\"height:24px; line-height:24px; font-weight:bold;\">";
	echo "<a href=\"contest.php?c_id=" . $row['c_id'] . "\">" . $row['c_name'] . "</a>    (" . $row[c_time] . ")<br/>";
	echo "</div>";
}

?>
</body>
</html>

