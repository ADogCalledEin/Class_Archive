<?php include("common.php"); ?>

<!DOCTYPE html>
<html>
	<?php head() ?>

	<body>
		<div id="frame">
			<?php banner(); ?>
			<div id="main">
				<h1>The One Degree of Kevin Bacon</h1>
				<p>Type in an actor's name to see if he/she was ever in a movie with Kevin Bacon!</p>
				<p><img src="https://webster.cs.washington.edu/images/kevinbacon/kevin_bacon.jpg" alt="Kevin Bacon" /></p>

				<!-- form to search for every movie by a given actor -->
				<?php searchAll(); ?>

				<!-- form to search for movies where a given actor was with Kevin Bacon -->
				<?php searchKevin(); ?>
			</div> <!-- end of #main div -->
		
			<?php validators(); ?>
		</div> <!-- end of #frame div -->
	</body>
</html>