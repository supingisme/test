<?php

$cmd = "sh shell.sh";
exec($cmd, $log, $status);
echo "$log, $status";
?>
