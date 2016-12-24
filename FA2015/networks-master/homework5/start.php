<?php 
	include("common.php"); 
	session_start();
    if(!(isset($_SESSION['user'])) && empty($_SESSION['user'])) {
?>
<!DOCTYPE html>
<html>
    
    <?php head(); ?>
	<body>
		<?php remember(); ?>
		<div id="main">
			<p>
				The best way to manage your tasks. <br />
				Never forget the cow (or anything else) again!
			</p>

			<p>
				Log in now to manage your to-do list. <br />
				If you do not have an account, one will be created for you.<br /><br />
				<strong>The user name must be 3-8 characters long, begin with a lowercase letter, and consist entirely of lowercase letters and numbers.</strong><br/>
				<strong>The password must be 6-12 characters long, begin with a number, and end with any character that is <em>not</em> a letter or number. </strong>
			</p>

			<form id="loginform" action="login.php" method="post">
				<div><input name="name" type="text" size="8" autofocus="autofocus" /> <strong>User Name</strong></div>
				<div><input name="password" type="password" size="8" /> <strong>Password</strong></div>
				<div><input type="submit" value="Log in" /></div>
			</form>

			<?php
				if(isset($_SESSION['error']) && ($_SESSION['error'] != "")){
					echo '<em id="problem">'.$_SESSION['error'].'</em>';
					$_SESSION['error'] = "";
				}
			?>
			<p>
				<?php
					if($_COOKIE['timestamp'] != ""){
				?>
				<em>(last login from this computer was <?= $_COOKIE['timestamp'];?>)</em>
				<?php } ?>
			</p>
		</div>
        <?php footer(); ?>
	</body>
</html>

<?php 
    }
    else{
        header("Location: todolist.php");
    }
?>
