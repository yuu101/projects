<div class="container">
	<div class="row form-group">
		<div class="col-md-3">
			<form class="form" role="search" action="<?php echo site_url('borrow/search') ?>" method="get" >
				<div class="input-group">
					<input type="text" class="form-control" placeholder="Search" name="search" value="<?php echo $condition ?>">
					<span class="input-group-btn">
					    <button class="btn btn-default" type="submit">Search</button>
					</span>
				</div>
			</form>
		</div>
		<div class="col-md-2 col-md-offset-2">
			<h3> 借書管理 </h3>
		</div>
		<div class="col-md-offset-3 col-md-1">
			<a href="<?php echo site_url('/returnbook') ?>" class="btn btn-primary next-mode">還書</a>
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
				<th>預約日期</th>
				<th>書籍狀態</th>
				<th>借書</th>
				<th>取消預約</th>
			<?php if ($reserves!=NULL): ?>
				<?php foreach ($reserves as $key => $reserve): ?>
					<tr>
						<td><?php echo $reserve->isbn ?></td>
						<td><?php echo $reserve->reserveC_id ?></td>
						<td><?php echo $reserve->bookName ?></td>
						<td><?php echo $reserve->reserveSSN ?></td>
						<td><?php echo $reserve->userName ?></td>
						<td><?php echo $reserve->date ?></td>
						<td class="bookstate"><?php echo (($reserve->return_date != NULL && $reserve->loan_date != null) || $reserve->loan_date == NULL) ? '可借書'  : '書籍尚未歸還' ?></td>
						<?php if (($reserve->return_date != NULL && $reserve->loan_date != null) || $reserve->loan_date == NULL): ?>
							<td ><a href="<?php echo site_url(['borrow/borrowbook',$reserve->reserveC_id,$reserve->reserveSSN]) ?>" class="btn btn-info btn-xs" data-toggle="modal" data-target="">借書</a></td>
						<?php else : ?>
							<td></td>
						<?php endif ?>
						<td><a href="<?php echo site_url(['borrow/destory',$reserve->reserveC_id]) ?>" class="btn btn-danger btn-xs">取消預約</a></td>			
					</tr>
				<?php endforeach ?>
			<?php endif ?>
		</table>
	</div>
</div>