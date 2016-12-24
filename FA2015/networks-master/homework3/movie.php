<!DOCTYPE html>
<?php
	$movie = $_GET["film"];
	$info = fopen($movie."/info.txt", "r") or die ("Unable to open file");
	$overview = fopen($movie."/overview.txt", "r") or die ("Cant do it captain!")
?>
<html>
		<meta charset="utf-8" />
			<?php
				$title=fgets($info);
				$year=fgets($info);
				$yword=trim($year);
				$rating=fgets($info);
			?>
	<head>
		<?php
			
			echo "<title>" .$title." - Rancid Tomatoes</title>";
			
		?>
	</head>

	<body>
		<link rel="stylesheet" type="text/css" href="movie.css"/>
		<div class="bghead">
			<img class="center" src="https://webster.cs.washington.edu/images/rancidbanner.png" alt="Rancid Tomatoes" />
		</div>

		<div>
			<?php
				echo "<h1>".$title." (".$yword.")</h1>"
			
			?>
		</div>
		
		
		
		<div class="box">
			<div class="floatright">
				<img src=<?php echo $movie."/overview.png" ?> alt="general overview" />
			</div>

		<div id="contentmain">
			<div class="contenttitle">
				<?php
				if ($rating > 60){
					echo '<span class="fresh">' .$rating. '%</span>';
					
				}else {
					echo '<span class="rotten">' .$rating. '%</span>';
				}
				?>

			</div>
			<?php
				$N = 0;
				$i = 1;
				while((file_exists($movie."/review".$i.".txt")) || (file_exists($movie."/review0".$i.".txt"))){
					$N++;
					$i++;
				}
			
			$left = round($N/2);
			$right = $N -$left;
			
			echo'<div id = "contentleft">';
			
			for ( $i=1; $i<=$left; $i++){
				 if (!(file_exists($movie."/review01.txt"))){
				 	$review = fopen($movie."/review".$i.".txt", "r");
				 }
				 else{
				 	$review = fopen($movie."/review0".$i.".txt", "r");
				 }
				$text = fgets($review);
				$tomato = fgets($review);
				$author = fgets($review);
				$pub = fgets($review);
				
				echo '<div class ="quote"> <p>';
				if (trim($tomato) == "FRESH"){
					echo '<img src="https://webster.cs.washington.edu/images/fresh.gif" alt="Fresh" />';
				}else{
					echo '<img src="https://webster.cs.washington.edu/images/rotten.gif" alt="Rotten" />';
				}
				echo "<q>".$text."</q> </p> </div>";
				echo '<div class="critic"> <p> <img src="https://webster.cs.washington.edu/images/critic.gif" alt="Critic" />';
				echo $author. '<br />';
				echo '<span class="publisher">'.$pub.'</span> </p> </div>';
				
				fclose($review);
			}
			echo '</div>';
			
			echo '<div id ="contentright">';
			
			for ( $f=$left+1; $f<=$N; $f++){
				 if (!(file_exists($movie."/review01.txt"))){
				 	$review = fopen($movie."/review".$f.".txt", "r");
				 }else{
				 	if($f > 9){
				 		$review=fopen($movie."/review".$f.".txt", "r");
				 	}else{
				 		$review=fopen($movie."/review0".$f.".txt", "r");
				 	}
				 }
				$text = fgets($review);
				$tomato = fgets($review);
				$author = fgets($review);
				$pub = fgets($review);
				
				echo '<div class ="quote"> <p>';
				if (trim($tomato) == 'FRESH'){
					echo '<img src="https://webster.cs.washington.edu/images/fresh.gif" alt="Fresh" />';
				}else{
					echo '<img src="https://webster.cs.washington.edu/images/rotten.gif" alt="Rotten" />';
				}
				echo "<q>".$text."</q> </p> </div>";
				echo '<div class="critic"> <p> <img src="https://webster.cs.washington.edu/images/critic.gif" alt="Critic" />';
				echo $author. '<br />';
				echo '<span class="publisher">'.$pub.'</span> </p> </div>';
				
				fclose($review);
			}
			echo '</div>';
			
			?>
		</div>
		<div id="description">
		 <?php
			echo "<dl>";
			while(!feof($overview)){
				$line = fgets($overview);
				$title = strtok($line, ":");
				$value = substr($line, strpos($line, ":")+1);
				echo "<dt>" .$title. "</dt>";
				echo "<dd>" .$value. "</dd>";
			}
			echo "</dl>";
			?> 
		
		</div>

		<div id="bottombar">
		<p class="clear">(1-10) of 88</p>
		</div>
		<div class="contenttitle">
				<?php
				if ($rating > 60){
					echo "<span class='fresh'>" .$rating. "%</span>";
					
				}else {
					echo "<span class='rotten'>" .$rating. "%</span>";
				}
				?>

			</div>
		
		</div>

		<div class="floatright">
			<a href="https://webster.cs.washington.edu/validate-html.php"><img src="https://webster.cs.washington.edu/images/w3c-html.png" alt="Valid HTML5" /></a><br />
			<a href="https://webster.cs.washington.edu/validate-css.php"><img src="https://webster.cs.washington.edu/images/w3c-css.png" alt="Valid CSS" /></a>
		</div>
		<div class="bghead">
			<img class="center" src="https://webster.cs.washington.edu/images/rancidbanner.png" alt="Rancid Tomatoes" />
		</div>

		
	</body>
</html>
