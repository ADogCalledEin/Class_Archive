<?php
    include("common.php");
    $db = connect();
    $firstname = $_GET["firstname"];
    $lastname = $_GET["lastname"];
    
    function findAllMovies($db, $firstname, $lastname) {
        try {
            $actorID = findActorID($db, $firstname, $lastname);
            $rows = $db->prepare("SELECT a.first_name, a.last_name, r.actor_id, m.name, m.year FROM roles r JOIN movies m ON r.movie_id = m.id JOIN actors a ON r.actor_id = a.id WHERE r.actor_id = '$actorID' ORDER BY m.year DESC");
            $rows->execute();
            $movies = $rows->fetchAll(PDO::FETCH_ASSOC);
            return $movies;
        }
        
        catch (Exception $e) {
            echo $e;
        } 
    }
?>

<!DOCTYPE html>
<html>
    <?php
        $movies = findAllMovies($db, $firstname, $lastname);
        // $actorfname = $movies[0]["first_name"];
        // $actorlname = $movies[0]["last_name"];
        if (count($movies) == 0) {
            notFound($firstname, $lastname);
            return;
        }
        head();
    ?>

    <body>
        <div id = "frame">
            <?php banner(); ?>
            <div id = "main">
                <h1>All Films for <?= $firstname ?> <?= $lastname ?></h1>
                <table>    
                    <tr>
                        <th>#</th>
                        <th>Name</th>
                        <th>Year</th>
                    </tr>
                    <?php
                        $count = 0;
                        foreach ($movies as $movie) {
                            $name = $movie["name"];
                            $year = $movie["year"];
                            $count++;
                    ?>
                    <tr>
                        <td><?= $count ?></td>
                        <td><?= $name ?></td>
                        <td><?= $year ?></td>
                    </tr>
                    <?php 
                        } 
                    ?>
                </table>
                <?php
                    searchAll();
                    searchKevin(); 
                ?>
            </div>
            <?php validators(); ?>
        </div>
    </body>
</html>