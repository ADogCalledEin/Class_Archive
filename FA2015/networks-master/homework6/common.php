<?php
	function banner() {
	    echo '<div id="banner">
				<a href="mymdb.php"><img src="https://webster.cs.washington.edu/images/kevinbacon/mymdb.png" alt="banner logo" /></a>
				My Movie Database
			  </div>';
	}
    
    function connect() {
        /*** connection credentials *******/
        $servername = "www.watzekdi.net";
        $username = "watzekdi_cs393";
        $password = "KevinBac0n";
        $database = "watzekdi_imdb";
        $dbport = 3306;
        
        /****** connect to database **************/
        try {
            $db = new PDO("mysql:host=$servername;dbname=$database;charset=utf8;port=$dbport", $username, $password);
        }
        
        catch(PDOException $e) {
            echo $e->getMessage();
        }
        
        return $db;
    }
    
    function findActorID($db, $firstname, $lastname) {
        try {
            // $firstname = $db->quote($firstname);
            // $lastname = $db->quote($lastname);
            $rows = $db->prepare("SELECT * FROM actors WHERE first_name LIKE '$firstname%' AND last_name = '$lastname' ORDER BY film_count DESC");
            $rows->execute();
            $actors = $rows->fetchAll(PDO::FETCH_ASSOC);
            $actor = findMostMovies($actors, $firstname, $lastname);
            return $actor["id"];
        }
        
        catch (Exception $e) {
            echo $e;
        } 
    }
    
    function findMostMovies($actors, $firstname, $lastname) {
        $count = count($actors);
        $actor = $actors[0];
        if ($count <= 1) {
            return $actor;
        }
        $most = $actor["film_count"];
        foreach ($actors as $act) {
            if ($act["film_count"] < $most) {
                return $actor;
            }
            elseif ($act["id"] < $actor["id"]) {
                $actor = $act;
            }
        }
    }
    
    function head() {
    	echo '<head>
    		  <title>My Movie Database (MyMDb)</title>
    		  <meta charset="utf-8" />
    		
    		  <!-- Links to provided files.  Do not edit or remove these links -->
    		  <link href="https://webster.cs.washington.edu/images/kevinbacon/favicon.png" type="image/png" rel="shortcut icon" />
    		  <script src="https://webster.cs.washington.edu/js/kevinbacon/provided.js" type="text/javascript"></script>
    
    		  <!-- Link to your CSS file that you should edit -->
    		  <link href="bacon.css" type="text/css" rel="stylesheet" />
    	      </head>';
	}
	
	function notFound($firstname, $lastname) {
	    head();
	    echo '<body>
	            <div id = "frame">';
        banner();
        echo '<div id = "main">
                <h1>No Results for '.$firstname.' '.$lastname.'</h1>';
        searchAll();
        searchKevin();
        echo '</div>';
        validators();
        echo '</div>
              </body>
              </html>';
	}
	
	function searchAll() {
	    echo '<form action="search-all.php" method="get">
					<fieldset>
						<legend>All movies</legend>
						<div>
							<input name="firstname" type="text" size="12" placeholder="first name" autofocus="autofocus" /> 
							<input name="lastname" type="text" size="12" placeholder="last name" /> 
							<input type="submit" value="go" />
						</div>
					</fieldset>
			  </form>';
	}
	
	function searchKevin() {
	    echo '<form action="search-kevin.php" method="get">
					<fieldset>
						<legend>Movies with Kevin Bacon</legend>
						<div>
							<input name="firstname" type="text" size="12" placeholder="first name" /> 
							<input name="lastname" type="text" size="12" placeholder="last name" /> 
							<input type="submit" value="go" />
						</div>
					</fieldset>
			  </form>';
	}
	
	function validators() {
	    echo '<div id="w3c">
				<a href="https://webster.cs.washington.edu/validate-html.php"><img src="https://webster.cs.washington.edu/images/w3c-html.png" alt="Valid HTML5" /></a>
				<a href="https://webster.cs.washington.edu/validate-css.php"><img src="https://webster.cs.washington.edu/images/w3c-css.png" alt="Valid CSS" /></a>
			  </div>';
	}
?>