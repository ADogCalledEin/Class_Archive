<?php
    include("common.php");
    $db = connect();
    $firstname = $_GET["firstname"];
    $lastname = $_GET["lastname"];
    
    function findAllKevins($db, $firstname, $lastname) {
        $kevinID = findActorID($db, "Kevin", "Bacon");
        $actorID = findActorID($db, $firstname, $lastname);
        $rows = $db->prepare("SELECT m.* FROM movies m JOIN roles r1 ON r1.movie_id = m.id JOIN roles r2 ON r2.movie_id = m.id JOIN actors a1 ON r1.actor_id = a1.id JOIN actors a2 ON r2.actor_id = a2.id WHERE a1.id = '$kevinID' AND a2.id = '$actorID' ORDER BY m.year DESC");
        $rows->execute();
        $movies = $rows->fetchAll(PDO::FETCH_ASSOC);
        return $movies;
    }
?>

<!DOCTYPE html>
<html>
    <?php
        $movies = findAllKevins($db, $firstname, $lastname);
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
                <h1>All Films with <?= $firstname ?> <?= $lastname ?> and Kevin Bacon</h1>
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