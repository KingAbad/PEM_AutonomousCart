<?php
require_once('config.php');
?>


<!DOCTYPE html>
<html>
<head>
	<title>User Registration | PHP</title>
	<link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
</head>
<body>

<div>
	<?php

	?>
</div>

<div>
	<form action="registration.php" method="post">
		<div class="container">
			
			<div class="row">
				<div class="col-sm-3">
					<h1>Registration</h1>
					<p>Fill up the form with correct values.</p>
					
					<hr class="mb-3">
					<label for="username"><b>Username</b></label>
					<input class="form-control" id="username" type="text" name="username" required>



					<label for="email"><b>Email Address</b></label>
					<input class="form-control" id="email"  type="email" name="email" required>


					<label for="password"><b>Password </b></label>
					<input class="form-control" id="password"  type="password" name="password" required>
					<hr class="mb-3">
					

					
					<input class="btn btn-primary" type="submit" id="register" name="create" value="Sign Up">

		</div>
									<p>
			Al geregistreerd? <a href="login.php">Meld aan</a>
		</p>
	</form>
</div>
























<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/sweetalert2@10"></script>
<script type ="text/javascript">
	$(function(num){
		 if ( ! num) { //This is the base case.
    return;
  }
  
  
		$('#register').click(function(e){
			
			
			var valid = this.form.checkValidity();
			
			
			if(valid){
			var username	= $('#username').val();
			var email		= $('#email').val();
			var password	= $('#password').val();

			
			
				e.preventDefault();
				
				$.ajax({
					type: 'POST',
					url: 'process.php',
					data: {username: username,email: email,password: password},
					success: function(data){
						
						if($.trim(data) === "succes"){
						setTimeout('window.location.href = "login.php"', 2000);
					}
					Swal.fire({
								'title': 'Successful',
								'text': data,
								'type': 'success'
																
								})
							
					},
					error: function(data){
						Swal.fire({
								'title': 'Errors',
								'text': 'There were errors while saving the data.',
								'type': 'error'
								})
					}
				});

				
			}else{
				
			}

			



		});		

		
	}) ;
</script>
</body>
</html>



























