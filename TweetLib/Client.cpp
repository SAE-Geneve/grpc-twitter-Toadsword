#include "Client.h"

namespace tweet {

	proto::TweetOut Client::Tweet(const proto::TweetIn in)
	{
		grpc::ClientContext client_context;
		proto::TweetOut out;
		auto status = stub_->Tweet(&client_context, in, &out);
		if (!status.ok())
			throw std::runtime_error("Tweet error.");

		return out;
	}

	proto::FollowOut Client::Follow(const proto::FollowIn in)
	{
		grpc::ClientContext client_context;
		proto::FollowOut out;
		auto status = stub_->Follow(&client_context, in, &out);
		if (!status.ok())
			throw std::runtime_error("Couldn't follow : " + in.name());

		return out;
	}

	proto::ShowOut Client::Show(const proto::ShowIn in)
	{
		grpc::ClientContext client_context;
		proto::ShowOut out;
		auto status = stub_->Show(&client_context, in, &out);
		if (!status.ok())
			throw std::runtime_error("Couldn't show : " + in.user());

		return out;
	}

	proto::LoginOut Client::Login(const proto::LoginIn in)
	{
		grpc::ClientContext client_context;
		proto::LoginOut out;
		auto status = stub_->Login(&client_context, in, &out);
		if (!status.ok())
			throw std::runtime_error("Couldn't login, please try again.");

		return out;
	}

	proto::LogoutOut Client::Logout(const proto::LogoutIn in)
	{
		grpc::ClientContext client_context;
		proto::LogoutOut out;
		auto status = stub_->Logout(&client_context, in, &out);
		if (!status.ok())
			throw std::runtime_error("Couldn't logout.");

		return out;
	}

	proto::RegisterOut Client::Register(const proto::RegisterIn in)
	{
		grpc::ClientContext client_context;
		proto::RegisterOut out;
		auto status = stub_->Register(&client_context, in, &out);
		if (!status.ok())
			throw std::runtime_error("Error while registering.");

		return out;
	}

} // End namespace tweet.
