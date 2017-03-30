<div class="container">
	<div class="row form-group">
		<div class="col-md-3">
			<form class="form" role="search" action="<?php echo site_url('return/search') ?>" method="get" >
				<div class="input-group">
					<input type="text" class="form-control" placeholder="Search" name="search" value="<?php echo $condition ?>">
					<span class="input-group-btn">
					    <button class="btn btn-default" type="submit">Search</button>
					</span>
				</div>
			</form>
		</div>
		<div class="col-md-2 col-md-offset-2">
			<h3> 還書管理 </h3>
		</div>
		<div class="col-md-offset-3 col-md-1">
			<a href="<?php echo site_url('/borrow') ?>" class="btn btn-primary next-mode">借書</a>
		</div>
	</div>
	<div class="row table-responsive">
		<table class="table table-hover">
			<tr>
				<th>ISBN</th>
				<th>C_ID</th>
				<th>書名</th>
				<th>SSN</th>
				<th>姓名</th>
				<th>借書日期</th>
				<th>還書</th>
			<?php if ($borrows!=NULL): ?>
				<?php foreach ($borrows as $key => $borrow): ?>
					<tr>
						<td><?php  ?></td>
						<td><?php  ?></td>
						<td><?php  ?></td>
						<td><?php  ?></td>
						<td><?php  ?></td>
						<td><?php  ?></td>						
						<td ><a href="<?php ?>" class="btn btn-info btn-xs" data-toggle="modal" data-target="">還書</a></td>
					</tr>
				<?php endforeach ?>
			<?php endif ?>
		</table>
	</div>
</div>