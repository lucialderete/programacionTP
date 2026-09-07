<?php
$ruta = '../';
require_once('encabezado.php');
require_once('funciones.php');
if (!empty($_POST['apellido']) && !empty($_POST['nombre']) && !empty($_POST['dni']) && !empty($_FILES['foto']['size']) && !empty($_POST['direccion']) && !empty($_POST['fecha_nacimiento'])) {
    $apellido = $_POST['apellido'];
    $nombre = $_POST['nombre'];
    $dni = $_POST['dni'];
    $direccion = $_POST['direccion'];
    $fechanac = $_POST['fecha_nacimiento'];
    $tipo = $_FILES['foto'];

    $carpetaDestino = '../fotos/';
    if (!file_exists($carpetaDestino)) {
        mkdir($carpetaDestino);
    }
    $destino = $carpetaDestino . $nuevoNombre;
    $nuevoNombre = renombrar($dni, $foto['name']);
    if (move_uploaded_file($foto['temp_name'], $destino)) {
        echo '<main class="container">
						<section class="row justify-content-center">
							<article class="col-8">
								<main class="card p-4 border border-dark">
									<section class="card-body">
									<h3 class="card-title text-center">Licencia de Conducir</h3>
									<hr>
									<section class="row">
        
									<article class="col-4 text-center">';
        echo "<img src='$destino' alt='Foto de $nombre $apellido' class='img-fluid rounded-circle' style='width:150px; height:150px; object-fit: cover;'>";

        echo '</article>
				<article class="col-8 d-flex flex-column justify-content-center">';
        echo '<p><strong>Apellido:</strong>' . $apellido . '</p>';
        echo '<p><strong>Nombre:</strong> ' . $nombre . '</p>';
        echo '<p><strong>DNI:</strong>' . $dni . '</p>';
        echo '<p><strong>Dirección:</strong> ' . $direccion . '</p>';
        echo '<p><strong>Fecha de Nacimiento:</strong>' . $fechanac . '</p>';
        echo '</article>
			</section>
			</section>
			</main>
			</article>
        </section>
        </main>';
    }
} else {
    echo '<p> error de envio </p>';
}

require_once('pie.php');
?>