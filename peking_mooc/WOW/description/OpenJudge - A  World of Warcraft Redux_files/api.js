var api={
	path:'/api/',
	fail:function(instance){
		if (!unloading) alert('无法访问网站，请检查互联网连接，然后重试');
	},
	
	deleteDialog:function(dialogId,callback){
		$.post(this.path+'dialog/delete/', {'dialogId':dialogId}, callback, 'json');
	},

	deletePost:function(postId,callback){
		$.post(this.path+'topic/delete-post/', {'postId':postId}, callback, 'json');
    },
    
    deleteTopic:function(topicId,callback){
		$.post(this.path+'topic/delete-topic/', {'topicId':topicId},callback, 'json');
    },
    deleteClass:function(classId,groupId,callback){
    	$.post(this.path+'class/delete/', {'classId':classId,'group':groupId},callback, 'json');
    },
    saveProblem:function(oid,id){
    	originalNumber = document.getElementById('originalNumber');
    	alert(originalNumber.value+'5555'+id);
    },
    addLang:function(problem_id,language){
    	$.post(this.path+'global-problem/addlang/', {'problem_id':problem_id,'language':language},function(){location.reload();}, 'json');
    },
    deleteContestProblem:function(contestId,problemNumber,callback){
    	if(problemNumber)
    		$.post(this.path+'contest/delete-problem/', {'contestId':contestId,'problemNumber':problemNumber},callback, 'json');
    },
    deleteContestIp:function(ruleID,callback){
    	$.post(this.path+'contest/delete-ip/', {'ruleID':ruleID},callback, 'json');
    },
    deleteContestBlackIp:function(ruleID,callback){
    	$.post(this.path+'contest/delete-blackip/', {'ruleID':ruleID},callback, 'json');
    },
    autoFileSize:function(filesize){
    	if(filesize>=1024*1024*1024) //是否超过1G
    		return Math.round(filesize*100/1024/1024/1024)/100+'GB';
    	if(filesize>=1024*1024) //是否超过1M
    		return Math.round(filesize*10/1024/1024)/10+'MB'; 
    	if(filesize>=1024) //是否超过1K
    		return Math.round(filesize/1024)+'KB'; 
    	return filesize+'Byte'; //默认为字节数 
    },
    oppositeChecked:function(){
		ele = $("#fileupload input[type='checkbox']");
		for(var i=0;i<ele.length;i++){
			ele[i].checked = ele[i].checked?false:true;
		}
	},
	/*	注册相关	*/
	logout:function(callback){
		$.post(this.path+'auth/logout/', {}, callback, 'json');
	},
	checkEmail:function(email,callback){
		$.post(this.path+'auth/check-email/', {'email':email}, callback, 'json');
	},
	checkName:function(user_name,callback){
		$.post(this.path+'auth/check-name/', {'user_name':user_name}, callback, 'json');
	},
	checkDomain:function(domain,callback){
		$.post(this.path+'auth/check-domain/', {'domain':domain}, callback, 'json');
	},
	joinGroup:function(groupId,callback){
		$.post(this.path+'group/join/', {'groupId':groupId}, callback, 'json');
	},
	leaveGroup:function(groupId,userId,callback){
		if(userId == null)
			$.post(this.path+'group/leave/', {'groupId':groupId}, callback, 'json');
		else
			$.post(this.path+'group/leave/', {'groupId':groupId,'userId':userId}, callback, 'json');;
	},
	addExam:function(userId) {
		$post(this.path+'api/exam/add', {'userId':userId}, callback, 'json');
	},
	deleteContest:function(contestId,callback){
		$.post(this.path+'contest/delete/', {'id':contestId}, callback, 'json');
	},
	printCompleted:function(print_id,callback){
		$.post(this.path+'contest/print-completed/', {'print_id':print_id}, callback, 'json');
	},
	switchLanguage:function(language){
		$.post(this.path+'language/switch/',{'language':language}, function(){location.reload();}, 'json');
	}
};

/* 
 * 全站首页正在进行的比赛滚动
 */
$(document).ready(function(){
	ticker_height = $('.contest-running').height();
	new_height = $('.contest-running .contest-intro').height();
	no_oflines = 0;
	rotate = true;
	
	$('.contest-running').hover(
			function(){
				rotate = false;
			},
			function(){
				rotate = true;
			}
	);
	scroll();
});
function scroll(){
	no_oflines += rotate ? -2 : 0;
	$('.contest-running .contest-intro').css('top','' + no_oflines + 'px');
	if(no_oflines < -1 * new_height) no_oflines = ticker_height;
	setTimeout(scroll,60);
}

/* 
 * 小组后台导航栏
 */
$(document).ready(function(){
	$('.nav-toggle').hover(
			function(){
				$(this).addClass('nav-toggle-current');
			},
			function(){
				$(this).removeClass('nav-toggle-current');
			}
	);
	$('.navi-menu ul').addClass('hide');
	$('.nav-toggle').click(
			function(){
				$(this).parent().find('ul').toggle();
			}
	);
});
$(document).ready(function(){
	$('.nav-menu-bar').hover(
			function(){
				$(this).parent().find('.nav-toggle').addClass('nav-toggle-current');
				$(this).parent().find('.nav-image').addClass('nav-image-hover');
			},
			function(){
				$(this).parent().find('.nav-toggle').removeClass('nav-toggle-current');
				$(this).parent().find('.nav-image').removeClass('nav-image-hover');
			}
	);
});
//小组顶栏下拉菜单
$(document).ready(function(){
	$('.account-link').hover(
		function(){
			$(this).addClass('current');
			$(this).find('.account-list').addClass("dis");
		},
		function(){
			$(this).removeClass('current');
			$(this).find('.account-list').removeClass("dis");
		}
	);
});





