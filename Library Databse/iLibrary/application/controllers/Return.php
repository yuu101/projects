<?php
defined('BASEPATH') OR exit('No direct script access allowed');
/**
* 
*/
class Returnbook extends CI_Controller
{
	
	function __construct()
	{
		parent::__construct();
		$this->load->model('borrow_return_model','borrow');
		if ($this->session->userdata('priority') < 1)  	//判斷進入者權限
		{
			$this->session->set_flashdata('message', '權限不足');
			$this->session->set_flashdata('type', 'danger');
			redirect('/index');     
		}
	}

	public function index()
	{
		$borrows = NULL;
		$condition = NULL;
		$this->load->view('layout/header');
		$this->load->view('layout/navbar');
		$this->load->view('library/borrow/returnbook',compact('borrows','condition'));
		$this->load->view('layout/footer');
	}

	public function search()
	{
		$condition = $this->input->get('search');
		$borrows = $this->borrow->search(['user.ssn','user.name','book.isbn','book.name','borrow.c_id'],$condition);
		if (!$reserves)
		{
			$this->session->set_flashdata('message', "搜尋不到借書記錄");
			$this->session->set_flashdata('type', 'danger');

			redirect('/return');
		}else
		{
			$this->load->view('layout/header');
			$this->load->view('layout/navbar');			
			$this->load->view('library/borrow/returnbook', compact('borrow','condition'));
			$this->load->view('layout/footer');
		}
	}

	public function destory($c_id,$isborrow=0,$isrecord=0)
	{
			
	}

	public function returnbook($c_id,$ssn)
	{
		
	}
}