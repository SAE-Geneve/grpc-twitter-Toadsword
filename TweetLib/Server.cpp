#include "Server.h"

namespace tweet {

	grpc::Status Server::Tweet(
		grpc::ServerContext* context, 
		const proto::TweetIn* request, 
		proto::TweetOut* response)
	{
		response->set_error(storage_->Tweet(context->peer(), request->content()));
		return grpc::Status::OK;
	}

	grpc::Status Server::Follow(
		grpc::ServerContext* context, 
		const proto::FollowIn* request, 
		proto::FollowOut* response)
	{
		response->set_error(storage_->Follow(context->peer(), request->name()));
		return grpc::Status::OK;
	}

	grpc::Status Server::Show(
		grpc::ServerContext* context, 
		const proto::ShowIn* request, 
		proto::ShowOut* response)
	{
		std::vector<TweetValue> tweets = storage_->Show(context->peer(), request->user());
        for(TweetValue tweet : tweets) {
			proto::TweetIn* newTweet = response->add_tweets();
			newTweet->set_user(tweet.name);
			newTweet->set_content(tweet.text);
			newTweet->set_time(tweet.time);
        }
		
		return grpc::Status::OK;
	}

	grpc::Status Server::Login(
		grpc::ServerContext* context, 
		const proto::LoginIn* request, 
		proto::LoginOut* response)
	{
		response->set_error(storage_->Login(context->peer(), request->user(), request->pass()));
		return grpc::Status::OK;
	}

	grpc::Status Server::Logout(
		grpc::ServerContext* context, 
		const proto::LogoutIn* request, 
		proto::LogoutOut* response)
	{
		response->set_error(storage_->Logout(context->peer()));
		return grpc::Status::OK;
	}

	grpc::Status Server::Register(
		grpc::ServerContext* context, 
		const proto::RegisterIn* request, 
		proto::RegisterOut* response)
	{
		response->set_error(storage_->Register(context->peer(), request->name(), request->pass()));
		return grpc::Status::OK;
	}

} // End namespace tweet.
