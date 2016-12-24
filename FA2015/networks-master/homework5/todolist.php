<?php 
    include("common.php"); 
	session_start();
    if(!(isset($_SESSION['user'])) && empty($_SESSION['user'])) {
       header("Location: start.php");
    }
    else{
        $username = $_SESSION["user"];
        if(file_exists("todo_".$username.".txt")){
            $data = fopen("todo_".$username.".txt", "r");
        }
        else{
            $my_file = "todo_".$username.".txt";
            $data = fopen($my_file, 'w') or die('Cannot open file:  '.$my_file);
            fclose($data);
            $data = fopen("todo_".$username.".txt", "r");
        }
?>
<!DOCTYPE html>
<html>
    <?php head(); ?>

	<body>
		<?php remember(); ?>

		<div id="main">
			<h2><?= $username; ?>'s To-Do List</h2>

			<ul id="todolist">
				<?php
					$line_number = 1;
					while(!feof($data)){
						$line = fgets($data);
						if(($line != '') && ($line != '\xA')){
						echo '<li>
							 <form action="submit.php" method="post">
						 	 <input type="hidden" name="action" value="delete" />
							 <input type="hidden" name="index" value="'.$line_number.'" />
							 <input type="submit" value="Delete" />
							 </form>
							 '.$line.'
							 </li>';
						}
						$line_number++;
					}
				?>
				<li>
					<form action="submit.php" method="post">
						<input type="hidden" name="action" value="add" />
						<input name="item" type="text" size="25" autofocus="autofocus" />
						<input type="submit" value="Add" />
					</form>
				</li>
			</ul>

			<div>
				<a href="logout.php"><strong>Log Out</strong></a>
				<em>(logged in since <?= $_COOKIE['timestamp']; ?>)</em>
			</div>

		</div>

		<?php footer(); ?>
	</body>
</html>
<?php } 
	fclose($data);
?>